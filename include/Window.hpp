#pragma once

class Window
{
	public:
	bool Init();
	void Destroy();

	void PoolEvents();

	void Clear();
	void Display();

	void SetClearColor(float r, float g, float b);

	bool IsOpen();
	void Close();
	bool IsNull();

	private:
	struct GLFWwindow * window;
	struct Color
	{
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
	};
	Color color;
};