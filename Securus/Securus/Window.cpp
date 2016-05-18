#include "Window.h"

Window::Window()
{
	
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Init()
{
	window = glfwCreateWindow(1280, 720, "GameApplication", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		printf("window create fail\n");
		return;
	}

	//glfwSetWindowSizeCallback(window, windowSizeCallback);
	glfwMakeContextCurrent(window);

	if (gl3wInit()) 
	{
		printf("gl3wfail\n");
	}

	screenWidth = 1280;
	screenHeight = 720;
}

void Window::Init(int width, int height, char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	window = glfwCreateWindow(width, height, title, monitor, share);

	if (!window)
	{
		glfwTerminate();
		printf("window create fail\n");
		return;
	}

	//glfwSetWindowSizeCallback(window, windowSizeCallback);
	glfwMakeContextCurrent(window);

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
	return glfwWindowShouldClose(window);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

void Window::windowSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	screenWidth	 = width;
	screenHeight = height;
}