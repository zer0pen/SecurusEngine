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

void Camera::PhysicsUpdate()
{
	if (transform.getIsChange())
	{
		cameraMatrix = glm::translate(orthoMatrix, transform.getPosition());
		cameraMatrix = glm::scale(cameraMatrix, transform.getScale());
		cameraMatrix = glm::rotate(cameraMatrix, transform.getDegree(), transform.getRotate());
		transform.setIsChange(false);
	}
}

void Camera::GraphicUpdate()
{

}


Transform Camera::getTransform()
{
	return transform;
}

glm::mat4 Camera::getCameraMatrix()
{
	return cameraMatrix;
}
