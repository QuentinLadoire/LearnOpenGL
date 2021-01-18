
#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool Window::Init()
{
	window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to Create GLFW window" << std::endl;

		return false;
	}

	glfwMakeContextCurrent(window);
	
	//GLAD Initialization
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

		return 1;
	}
	//------------------

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
}
void Window::Destroy()
{
	if (window != nullptr)
		glfwDestroyWindow(window);
}

void Window::PoolEvents()
{
	glfwPollEvents();
}

void Window::Clear()
{
	glClearColor(color.r, color.g, color.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Window::Display()
{
	glfwSwapBuffers(window);
}

void Window::SetClearColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

bool Window::IsOpen()
{
	return window != nullptr || !glfwWindowShouldClose(window);
}
void Window::Close()
{
	glfwSetWindowShouldClose(window, true);
}
bool Window::IsNull()
{
	return window == nullptr;
}