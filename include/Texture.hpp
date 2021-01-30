#pragma once

#include <string>

enum class WrapMode
{
	Repeat,
	Mirror,
	ClampToEdge,
	ClampToBorder,
	Count
};

enum class FilterMode
{
	Nearest,
	Linear,
	Count
};

class Image;

class Texture
{
	public:
	Texture();
	~Texture();

	const unsigned int GetId() const;

	const int GetWidth() const;
	const int GetHeight() const;

	const WrapMode GetWrapMode() const;
	const FilterMode GetFilterMode() const;

	void SetWrapMode(const WrapMode wrapMode);
	void SetFilterMode(const FilterMode filterMode);

	void LoadFromImage(Image& image);

	private:
	unsigned int m_id = 0;
	int m_width = 0;
	int m_height = 0;

	Image* m_image = nullptr;

	WrapMode m_wrapMode = WrapMode::Repeat;
	FilterMode m_filterMode = FilterMode::Nearest;
};