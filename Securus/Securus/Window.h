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

protected:
	virtual void windowSizeCallback(GLFWwindow* window, int width, int height);

private:
	GLFWwindow* window;
	int screenWidth, screenHeight;
};
