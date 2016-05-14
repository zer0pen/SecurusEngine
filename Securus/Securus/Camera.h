#pragma once
#include <glm.hpp>
#include <gtx/transform.hpp>

class Camera
{
public:
	Camera();
	Camera(float width, float height);
	~Camera();

	void translateCamera(glm::vec3 position);
	glm::mat4 getCameraMatrix();
	
private:
	glm::mat4 orthoMatrix;

	glm::mat4 cameraMatrix;
};

