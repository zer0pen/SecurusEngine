#include "stdafx.h"

Shader::Shader()
{
}

Shader::~Shader()
{
}

GLuint Shader::GetProgram()
{
	return program;
}

void Shader::Init()
{
	program = glCreateProgram();
	fs = LoadShader("./shader/fs.txt", GL_FRAGMENT_SHADER, false);

	vs = LoadShader("./shader/vs.txt", GL_VERTEX_SHADER, false);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

GLuint Shader::LoadShader(const char * filename, GLenum shader_type, bool check_errors)
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

	data = new char[filesize + 1];

	if (!data)
		goto fail_data_alloc;

	fread(data, 1, filesize, fp);
	data[filesize] = 0;
	fclose(fp);

	result = glCreateShader(shader_type);

	if (!result)
		goto fail_shader_alloc;

	glShaderSource(result, 1, &data, NULL);

	delete[] data;

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
