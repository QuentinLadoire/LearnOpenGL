
#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void InitGLFW()
{
	if (!glfwInit())
		throw std::runtime_error{ "Failed to Initialize GLFW" };
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}
void GladLoadProcAddress()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error{ "Failed to initialize GLAD" };
}

void Window::Init(int width, int height, const char* title)
{
	InitGLFW();

	instance.glfwWindow = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (instance.glfwWindow == nullptr)
		throw std::runtime_error{ "Failed to Create GLFW Window" };

	glfwMakeContextCurrent(instance.glfwWindow);
	GladLoadProcAddress();

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(instance.glfwWindow, FramebufferSizeCallback);
}
void Window::Destroy()
{
	if (instance.glfwWindow != nullptr)
	{
		glfwDestroyWindow(instance.glfwWindow);
		glfwTerminate();
	}
}

void Window::PoolEvents()
{
	glfwPollEvents();
}

void Window::Clear()
{
	glClearColor(instance.color.r, instance.color.g, instance.color.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Window::Display()
{
	glfwSwapBuffers(instance.glfwWindow);
}

void Window::SetClearColor(float r, float g, float b)
{
	instance.color.r = r;
	instance.color.g = g;
	instance.color.b = b;
}
void Window::SetWindowMode()
{
	
}

bool Window::IsNull()
{
	return instance.glfwWindow == nullptr;
}
bool Window::IsOpen()
{
	return !IsNull() && !glfwWindowShouldClose(instance.glfwWindow);
}
void Window::Close()
{
	glfwSetWindowShouldClose(instance.glfwWindow, true);
}

Window Window::instance = Window();
