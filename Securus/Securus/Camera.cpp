#include "stdafx.h"

Camera::Camera()
{
	orthoMatrix = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
	cameraMatrix = orthoMatrix;
}

Camera::Camera(float width, float height)
{
	orthoMatrix = glm::ortho(0.0f, width, 0.0f, height);
	cameraMatrix = orthoMatrix;
}

Camera::~Camera()
{
}

void Camera::translateCamera(glm::vec3 position)
{
	cameraMatrix = glm::translate(cameraMatrix, position);
}

glm::mat4 Camera::getCameraMatrix()
{
	return cameraMatrix;
}
