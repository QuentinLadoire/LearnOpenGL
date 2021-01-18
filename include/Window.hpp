#pragma once

enum class WindowMode
{
	Windowed,
	Fullscreen,
	Borderless
};

class Window
{
	public:
	static void Init(int width, int height, const char* title);
	static void Destroy();

	static void PoolEvents();

	static void Clear();
	static void Display();

	static void SetClearColor(float r, float g, float b);
	static void SetWindowMode();

	static bool IsNull();
	static bool IsOpen();
	static void Close();

	private:
	struct GLFWwindow* glfwWindow;
	struct Color
	{
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
	};
	Color color;

	private:
	static Window instance;
};