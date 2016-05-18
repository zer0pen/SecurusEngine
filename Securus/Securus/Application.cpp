#include "stdafx.h"

Application::Application()
{
	window = new Window();
	shader = new Shader();
	camera = new Camera();
	currentScene = nullptr;
}

Application::~Application()
{
}

void Application::Init()
{
	if (!glfwInit())
	{
		printf("glfw fail\n");
	}
	window->Init();
	shader->Init();
}

void Application::Update()
{
	while (!window->windowShouldClose())
	{
		PhysicsUpdate();
		GraphicUpdate();
		window->swapBuffers();
		window->pollEvents();
	}
}

void Application::PhysicsUpdate()
{
	currentScene->PhysicsUpdate();
}

void Application::GraphicUpdate()
{
	glClearDepth(1.0);
	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glUseProgram(shader -> GetProgram());

	GLint pLocation = glGetUniformLocation(shader -> GetProgram(), "p");
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(camera->getCameraMatrix()[0][0]));
	currentScene->GraphicUpdate();
}

void Application::ChangeScene(Scene *nextScene)
{
	if(currentScene != nullptr)
		delete currentScene;

	currentScene = nextScene;
}
