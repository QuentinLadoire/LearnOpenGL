
#include "Texture.h"

#include <iostream>
#include <stb_image/std_image.hpp>
#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

Texture::Texture(const std::string texturePath)
{
	stbi_set_flip_vertically_on_load(true);

	int channels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &channels, 0);
	if (!data)
		throw std::runtime_error{ "Texture Error : Failed to load texture at " + texturePath + "\n" };

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto extension = texturePath.substr(texturePath.find_last_of('.'));
	if (extension == ".png")
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else if (extension == ".jpg")
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		throw std::runtime_error{ "Texture Error : " + extension + "not supported\n" };
	}

	stbi_image_free(data);
}
Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

const unsigned int Texture::GetId() const
{
	return id;
}
const int Texture::GetWidth() const
{
	return width;
}
const int Texture::GetHeight() const
{
	return height;
}
