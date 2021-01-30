
#include "Texture.hpp"

#include <iostream>
#include <stb_image/std_image.hpp>
#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

#include "Image.hpp"

static const int getWrapMode[static_cast<int>(WrapMode::Count)]
{
	GL_REPEAT,
	GL_MIRRORED_REPEAT,
	GL_CLAMP_TO_EDGE,
	GL_CLAMP_TO_BORDER
};

static const int getFilterMode[static_cast<int>(FilterMode::Count)]
{
	GL_NEAREST,
	GL_LINEAR
};

Texture::Texture()
{
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, getWrapMode[static_cast<int>(m_wrapMode)]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, getWrapMode[static_cast<int>(m_wrapMode)]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, getFilterMode[static_cast<int>(m_filterMode)]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, getFilterMode[static_cast<int>(m_filterMode)]);
}
Texture::~Texture()
{
	glDeleteTextures(1, &m_id);
}

const unsigned int Texture::GetId() const
{
	return m_id;
}
const int Texture::GetWidth() const
{
	return m_width;
}
const int Texture::GetHeight() const
{
	return m_height;
}

const WrapMode Texture::GetWrapMode() const
{
	return m_wrapMode;
}
const FilterMode Texture::GetFilterMode() const
{
	return m_filterMode;
}

void Texture::SetWrapMode(WrapMode wrapMode)
{
	m_wrapMode = wrapMode;
}
void Texture::SetFilterMode(FilterMode filterMode)
{
	m_filterMode = filterMode;
}

void Texture::LoadFromImage(Image& image)
{
	m_image = &image;
	m_width = image.GetWidth();
	m_height = image.GetHeight();

	glBindTexture(GL_TEXTURE_2D, m_id);

	if (m_image->GetChannels() == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.GetData());
	}
	else if (m_image->GetChannels() == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetData());
	}
}
