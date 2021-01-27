#pragma once

#include <string>

class Texture
{
	public:
	Texture(const std::string texturePath);
	~Texture();

	const unsigned int GetId() const;
	const int GetWidth() const;
	const int GetHeight() const;

	private:
	unsigned int id;
	int width;
	int height;
};