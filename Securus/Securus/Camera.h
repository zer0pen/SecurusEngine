#pragma once

class Camera : public Object
{
public:
	Camera();
	Camera(float width, float height);
	~Camera();

	glm::mat4 getCameraMatrix();
	Transform getTransform();

	void PhysicsUpdate();
	void GraphicUpdate();

private:
	Transform transform;
	glm::mat4 orthoMatrix;
	glm::mat4 cameraMatrix;
};
