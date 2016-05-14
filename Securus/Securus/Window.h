#pragma once
#include <glfw3.h>
#include <stdio.h>

class Window
{
public:
	Window();
	Window(int width, int height, char* title, GLFWmonitor* monitor = nullptr,GLFWwindow* share = nullptr);
	~Window();

	int getScreenWidth();
	int getScreenHeight();

	int windowShouldClose();
	void swapBuffers();
	void pollEvents();
protected:
	virtual void windowSizeCallback(GLFWwindow* window, int width, int height);

private:
	GLFWwindow* window;
	int screenWidth, screenHeight;
};

