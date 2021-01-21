#pragma once

enum class KeyCode
{
	Unknown = -1,
	Space,
	Apostrophe,
	Comma,
	Minus,
	Period,
	Slash,
	Alpha0,
	Alpha1,
	Alpha2,
	Alpha3,
	Alpha4,
	Alpha5,
	Alpha6,
	Alpha7,
	Alpha8,
	Alpha9,
	Semicolon,
	Equal,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	LeftBracket,
	Backslash,
	RightBracket,
	GraveAccent,
	World1,
	World2,
	Escape,
	Enter,
	Tab,
	Backspace,
	Insert,
	Delete,
	RightArrow,
	LeftArrow,
	DownArrow,
	UpArrow,
	PageUp,
	PageDown,
	Home,
	End,
	CapsLock,
	ScrollLock,
	NumLock,
	PrintScreen,
	Pause,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	F13,
	F14,
	F15,
	F16,
	F17,
	F18,
	F19,
	F20,
	F21,
	F22,
	F23,
	F24,
	F25,
	Keypad0,
	Keypad1,
	Keypad2,
	Keypad3,
	Keypad4,
	Keypad5,
	Keypad6,
	Keypad7,
	Keypad8,
	Keypad9,
	KeypadPeriod,
	KeypadDivide,
	KeypadMultiply,
	KeypadSubstract,
	KeypadAdd,
	KeypadEnter,
	KeypadEqual,
	LeftShift,
	LeftControl,
	LeftAlt,
	LeftSuper,
	RightShift,
	RightControl,
	RightAlt,
	RightSuper,
	Menu,
	KeyCount
};

class Window
{
	public:
	static void Init(int width, int height, const char* title);
	static void Destroy();

	static void PoolEvents();

	static void Clear();
	static void Display();

	static void SetTitle(const char* title);
	static void SetClearColor(float r, float g, float b);

	static void SetWindowedMode();
	static void SetFullscreenMode();
	static void SetBorderlessMode();

	static bool IsKeyPress(KeyCode keyCode);

	static bool IsNull();
	static bool IsOpen();
	static void Close();

	private:
	struct GLFWwindow* glfwWindow = nullptr;
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