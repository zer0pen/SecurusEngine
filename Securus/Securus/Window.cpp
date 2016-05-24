#include "stdafx.h"

Window::Window()
{
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Init()
{
	glfwWindow = glfwCreateWindow(1280, 720, "GameApplication", nullptr, nullptr);

	if (!glfwWindow)
	{
		glfwTerminate();
		printf("window create fail\n");
		return;
	}

	glfwMakeContextCurrent(glfwWindow);

	if (gl3wInit())
	{
		printf("gl3wfail\n");
	}

	screenWidth = 1280;
	screenHeight = 720;
}

void Window::Init(int width, int height, char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwWindow = glfwCreateWindow(width, height, title, monitor, share);

	if (!glfwWindow)
	{
		glfwTerminate();
		printf("window create fail\n");
		return;
	}

	glfwMakeContextCurrent(glfwWindow);

	if (gl3wInit())
	{
		printf("gl3wfail\n");
	}

	screenWidth = width;
	screenHeight = height;
}

int Window::getScreenWidth()
{
	return screenWidth;
}

int Window::getScreenHeight()
{
	return screenHeight;
}

int Window::windowShouldClose()
{
	return glfwWindowShouldClose(glfwWindow);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::swapBuffers()
{
	glfwSwapBuffers(glfwWindow);
}

/*
void Window::windowSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	screenWidth	 = width;
	screenHeight = height;
}
*/

