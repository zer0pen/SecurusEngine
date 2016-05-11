#include <stdio.h>
#include <gl3w.h>
#include <glfw3.h>
#include <FreeImage.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

using namespace std;

void Init();
void LoadTexture(char* path);
GLuint LoadShader(const char * filename, GLenum shader_type, bool check_errors);
void Render();

GLuint image, program, vao, fs, vs;
GLint mv_location, proj_location;

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (gl3wInit()) {
		return -1;
	}

	Init();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		Render();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void Init()
{
	program = glCreateProgram();
	fs = LoadShader("./shader/fs.txt",GL_FRAGMENT_SHADER,false);

	vs = LoadShader("./shader/vs.txt",GL_VERTEX_SHADER,false);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	//mv_location = glGetUniformLocation(program, "mv_matrix");
	//proj_location = glGetUniformLocation(program, "proj_matrix");
	//

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const GLfloat data[] = {
		 1.0,  1.0, 1.0, 1.0,
		-1.0,  1.0, 1.0, 1.0,
		-1.0, -1.0, 1.0, 1.0,

		-1.0, -1.0, 1.0, 1.0,
		 1.0, -1.0, 1.0, 1.0,
		 1.0,  1.0, 1.0, 1.0,
	};
	const GLfloat data2[] =
	{
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	GLuint buffer, buffer2;
	glGenBuffers(1, &buffer);
	glGenBuffers(1, &buffer2);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(data),data,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, buffer2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data2), data2, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//LoadTexture("./image/a.jpg");
	LoadTexture("./image/asdf.png");
}

void Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, green);
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void LoadTexture(char* fileName)
{
	GLuint texture;

	FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(fileName);
	FIBITMAP* image = FreeImage_Load(formato, fileName);
	

	if (FreeImage_GetBPP(image) != 32)
		image = FreeImage_ConvertTo32Bits(image);

	int width = FreeImage_GetWidth(image);
	int height = FreeImage_GetHeight(image);
 
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(image));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	GLenum huboError = glGetError();
	if(huboError){
		printf("There was an error loading the texture\n");
	}
	FreeImage_Unload(image);
}

GLuint LoadShader(const char * filename, GLenum shader_type, bool check_errors)
{
	GLuint result = 0;
	FILE * fp;
	size_t filesize;
	char * data;

	fp = fopen(filename, "rb");

	if (!fp)
	{
		printf("Shader load error\n");
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	data = new char [filesize + 1];

	if (!data)
		goto fail_data_alloc;

	fread(data, 1, filesize, fp);
	data[filesize] = 0;
	fclose(fp);

	result = glCreateShader(shader_type);

	if (!result)
		goto fail_shader_alloc;

	glShaderSource(result, 1, &data, NULL);

	delete [] data;

	glCompileShader(result);

	if (check_errors)
	{
		GLint status = 0;
		glGetShaderiv(result, GL_COMPILE_STATUS, &status);

		if (!status)
		{
			char buffer[4096];
			glGetShaderInfoLog(result, 4096, NULL, buffer);
#ifdef _WIN32
			OutputDebugStringA(filename);
			OutputDebugStringA(":");
			OutputDebugStringA(buffer);
			OutputDebugStringA("\n");
#else
			fprintf(stderr, "%s: %s\n", filename, buffer);
#endif
			goto fail_compile_shader;
		}
	}

	return result;

fail_compile_shader:
	printf("AAA");
	glDeleteShader(result);

fail_shader_alloc:;
fail_data_alloc:
	return result;
}