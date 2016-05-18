#pragma once

class Application : public Object
{
public:
	Application();
	~Application();

	void Init();
	void Update();
	void PhysicsUpdate();
	void GraphicUpdate();
	void ChangeScene(Scene *_nextScene);

private:
	Window *window;
	Shader *shader;
	Scene  *currentScene;
	Camera *camera;
};
