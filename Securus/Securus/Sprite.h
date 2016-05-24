#pragma once

class Sprite : public Component
{
public:
	Sprite(float x, float y, char* filePath);
	~Sprite();
	void LoadTexture(char* fileName);

	void PhysicsUpdate();
	void GraphicUpdate();

private:
	Sprite();

	GLfloat verticesData[12];
	GLfloat uvData[12];
	float x, y, width, height;
	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint textureID;
};
