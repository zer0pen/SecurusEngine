#pragma once
#include <gl3w.h>
#include "Object.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "Shader.h"

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
	Shader *shaer;
	Scene  *currentScene;
};

