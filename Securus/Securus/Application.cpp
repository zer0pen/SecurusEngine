#include "Application.h"

#define SAFE_DELETE(p) if(p) delete p;

Application::Application()
{
	
}

Application::~Application()
{
}

void Application::Init()
{

}

void Application::Update()
{
	PhysicsUpdate();
	GraphicUpdate();
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
	glUseProgram(program);

	GLint pLocation = glGetUniformLocation(program, "p");
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(myCamera->getCameraMatrix()[0][0]));
	currentScene->GraphicUpdate();
}

void Application::ChangeScene(Scene *nextScene)
{
	SAFE_DELETE(currentScene);
	currentScene = nextScene;
}