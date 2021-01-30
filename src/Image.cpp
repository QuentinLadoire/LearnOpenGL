
#include "Image.hpp"

#include <iostream>
#include <stb_image/std_image.hpp>

Image::Image(const std::string& imagePath, bool flip)
{
	stbi_set_flip_vertically_on_load(flip);

	unsigned char* data = stbi_load(imagePath.c_str(), &m_width, &m_height, &m_channels, 0);
	if (!data)
		throw std::runtime_error{ "Image Error : Failed to load image at " + imagePath + "\n" };
}
Image::~Image()
{
	stbi_image_free(m_data);
}

const int Image::GetHeight() const
{
	return m_height;
}
const int Image::GetWidth() const
{
	return m_width;
}
const int Image::GetChannels() const
{
	return m_channels;
}
const unsigned char* Image::GetData() const
{
	return m_data;
}
