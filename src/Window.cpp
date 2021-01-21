
#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

static const int GLFWKey[static_cast<int>(KeyCode::KeyCount)]
{
	GLFW_KEY_SPACE,
	GLFW_KEY_APOSTROPHE,
	GLFW_KEY_COMMA,
	GLFW_KEY_MINUS,
	GLFW_KEY_PERIOD,
	GLFW_KEY_SLASH,
	GLFW_KEY_0,
	GLFW_KEY_1,
	GLFW_KEY_2,
	GLFW_KEY_3,
	GLFW_KEY_4,
	GLFW_KEY_5,
	GLFW_KEY_6,
	GLFW_KEY_7,
	GLFW_KEY_8,
	GLFW_KEY_9,
	GLFW_KEY_SEMICOLON,
	GLFW_KEY_EQUAL,
	GLFW_KEY_A,
	GLFW_KEY_B,
	GLFW_KEY_C,
	GLFW_KEY_D,
	GLFW_KEY_E,
	GLFW_KEY_F,
	GLFW_KEY_G,
	GLFW_KEY_H,
	GLFW_KEY_I,
	GLFW_KEY_J,
	GLFW_KEY_K,
	GLFW_KEY_L,
	GLFW_KEY_M,
	GLFW_KEY_N,
	GLFW_KEY_O,
	GLFW_KEY_P,
	GLFW_KEY_Q,
	GLFW_KEY_R,
	GLFW_KEY_S,
	GLFW_KEY_T,
	GLFW_KEY_U,
	GLFW_KEY_V,
	GLFW_KEY_W,
	GLFW_KEY_X,
	GLFW_KEY_Y,
	GLFW_KEY_Z,
	GLFW_KEY_LEFT_BRACKET,
	GLFW_KEY_BACKSLASH,
	GLFW_KEY_RIGHT_BRACKET,
	GLFW_KEY_GRAVE_ACCENT,
	GLFW_KEY_WORLD_1,
	GLFW_KEY_WORLD_2,
	GLFW_KEY_ESCAPE,
	GLFW_KEY_ENTER,
	GLFW_KEY_TAB,
	GLFW_KEY_BACKSPACE,
	GLFW_KEY_INSERT,
	GLFW_KEY_DELETE,
	GLFW_KEY_RIGHT,
	GLFW_KEY_LEFT,
	GLFW_KEY_DOWN,
	GLFW_KEY_UP,
	GLFW_KEY_PAGE_UP,
	GLFW_KEY_PAGE_DOWN,
	GLFW_KEY_HOME,
	GLFW_KEY_END,
	GLFW_KEY_CAPS_LOCK,
	GLFW_KEY_SCROLL_LOCK,
	GLFW_KEY_NUM_LOCK,
	GLFW_KEY_PRINT_SCREEN,
	GLFW_KEY_PAUSE,
	GLFW_KEY_F1,
	GLFW_KEY_F2,
	GLFW_KEY_F3,
	GLFW_KEY_F4,
	GLFW_KEY_F5,
	GLFW_KEY_F6,
	GLFW_KEY_F7,
	GLFW_KEY_F8,
	GLFW_KEY_F9,
	GLFW_KEY_F10,
	GLFW_KEY_F11,
	GLFW_KEY_F12,
	GLFW_KEY_F13,
	GLFW_KEY_F14,
	GLFW_KEY_F15,
	GLFW_KEY_F16,
	GLFW_KEY_F17,
	GLFW_KEY_F18,
	GLFW_KEY_F19,
	GLFW_KEY_F20,
	GLFW_KEY_F21,
	GLFW_KEY_F22,
	GLFW_KEY_F23,
	GLFW_KEY_F24,
	GLFW_KEY_F25,
	GLFW_KEY_KP_0,
	GLFW_KEY_KP_1,
	GLFW_KEY_KP_2,
	GLFW_KEY_KP_3,
	GLFW_KEY_KP_4,
	GLFW_KEY_KP_5,
	GLFW_KEY_KP_6,
	GLFW_KEY_KP_7,
	GLFW_KEY_KP_8,
	GLFW_KEY_KP_9,
	GLFW_KEY_KP_DECIMAL,
	GLFW_KEY_KP_DIVIDE,
	GLFW_KEY_KP_MULTIPLY,
	GLFW_KEY_KP_SUBTRACT,
	GLFW_KEY_KP_ADD,
	GLFW_KEY_KP_ENTER,
	GLFW_KEY_KP_EQUAL,
	GLFW_KEY_LEFT_SHIFT,
	GLFW_KEY_LEFT_CONTROL,
	GLFW_KEY_LEFT_ALT,
	GLFW_KEY_LEFT_SUPER,
	GLFW_KEY_RIGHT_SHIFT,
	GLFW_KEY_RIGHT_CONTROL,
	GLFW_KEY_RIGHT_ALT,
	GLFW_KEY_RIGHT_SUPER,
	GLFW_KEY_MENU,
};

void FramebufferSizeCallback(GLFWwindow*, int width, int height)
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

	instance.glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (instance.glfwWindow == nullptr)
		throw std::runtime_error{ "Failed to Create GLFW Window" };

	glfwMakeContextCurrent(instance.glfwWindow);
	GladLoadProcAddress();

	glViewport(0, 0, width, height);
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

void Window::SetTitle(const char* title)
{
	glfwSetWindowTitle(instance.glfwWindow, title);
}
void Window::SetClearColor(float r, float g, float b)
{
	instance.color.r = r;
	instance.color.g = g;
	instance.color.b = b;
}

void Window::SetWindowedMode()
{
	const auto videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowMonitor(instance.glfwWindow, NULL, 5, 30, videoMode->width, videoMode->height, videoMode->refreshRate);
}
void Window::SetFullscreenMode()
{
	const auto videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowMonitor(instance.glfwWindow, glfwGetPrimaryMonitor(), 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
}
void Window::SetBorderlessMode()
{
	const auto videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);
	glfwSetWindowMonitor(instance.glfwWindow, glfwGetPrimaryMonitor(), 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
}

bool Window::IsKeyPress(KeyCode keyCode)
{
	return glfwGetKey(instance.glfwWindow, GLFWKey[static_cast<int>(keyCode)]) == GLFW_PRESS;
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
