#pragma once

class Shader
{
public:
	Shader();
	~Shader();
	void Init();
	GLuint LoadShader(const char * filename, GLenum shader_type, bool check_errors);
	GLuint GetProgram();
private:
	GLuint program, fs, vs, vao;
};
