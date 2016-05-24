#include "stdafx.h"

Sprite::Sprite(float x, float y, char* filePath)
{
	LoadTexture(filePath);

	//first
	verticesData[0] = x + width;		verticesData[1] = y + height;
	verticesData[2] = x;			verticesData[3] = y + height;
	verticesData[4] = x;			verticesData[5] = y;

	//second
	verticesData[6] = x;			verticesData[7] = y;
	verticesData[8] = x + width;		verticesData[9] = y;
	verticesData[10] = x + width;	verticesData[11] = y + height;

	uvData[0]  = 1.0f;	uvData[1]  = 1.0f;
	uvData[2]  = 0.0f;	uvData[3]  = 1.0f;
	uvData[4]  = 0.0f;	uvData[5]  = 0.0f;
	uvData[6]  = 0.0f;	uvData[7]  = 0.0f;
	uvData[8]  = 1.0f;	uvData[9]  = 0.0f;
	uvData[10] = 1.0f;	uvData[11] = 1.0f;

	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &uvBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesData), verticesData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvData), uvData, GL_STATIC_DRAW);
}

Sprite::~Sprite()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	glDeleteTextures(1, &textureID);
}

void Sprite::PhysicsUpdate()
{
}

void Sprite::GraphicUpdate()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}


void Sprite::LoadTexture(char* fileName)
{
	FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(fileName);
	FIBITMAP* image = FreeImage_Load(formato, fileName);

	if (FreeImage_GetBPP(image) != 32)
		image = FreeImage_ConvertTo32Bits(image);

	width  = (float)FreeImage_GetWidth(image);
	height = (float)FreeImage_GetHeight(image);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width, (GLsizei)height, 0, GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(image));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLenum huboError = glGetError();
	if (huboError)
	{
		printf("There was an error loading the texture\n");
	}
	FreeImage_Unload(image);
}
