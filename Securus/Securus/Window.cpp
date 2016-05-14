#include "Window.h"

Window::Window()
{
	if (!glfwInit())
	{
		printf("window create fail1\n");
		return;
	}

	window = glfwCreateWindow(1280, 720, "GameApplication", nullptr, nullptr);
	
	if(!window)
	{
		glfwTerminate();
		printf("window create fail2\n");
		return;
	}

	//glfwSetWindowSizeCallback(window, windowSizeCallback);
	glfwMakeContextCurrent(window);

	screenWidth = 1280;
	screenHeight = 720;
}

Window::Window(int width, int height, char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	if (glfwInit())
	{
		printf("window create fail\n");
		return;
	}

	window = glfwCreateWindow(width, height, title, monitor, share);
	screenWidth = width;
	screenHeight = height;
}

Window::~Window()
{
	glfwTerminate();
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