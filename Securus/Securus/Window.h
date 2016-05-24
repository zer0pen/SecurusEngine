#pragma once

class Window
{
public:
	Window();
	~Window();

	int getScreenWidth();
	int getScreenHeight();

	int windowShouldClose();
	void swapBuffers();
	void pollEvents();

	void Init();
	void Init(int width, int height, char* title, GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr);

private:
	GLFWwindow* glfwWindow;
	int screenWidth, screenHeight;
};
