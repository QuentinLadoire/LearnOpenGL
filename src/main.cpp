
#include <iostream>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

#include "Window.hpp"

int main()
{
	Window::Init(800, 600, "LearnOpenGL");

	while (Window::IsOpen())
	{
		Window::PoolEvents();

		Window::Clear();
		
		//rendering here

		Window::Display();
	}

	Window::Destroy();

	return 0;
}