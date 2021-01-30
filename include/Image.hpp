#pragma once

#include <string>

class Image
{
	public:
	Image(const std::string& imagePath, bool flip = true);
	~Image();

	const int GetWidth() const;
	const int GetHeight() const;
	const int GetChannels() const;
	const unsigned char* GetData() const;

	private:
	int m_width = 0;
	int m_height = 0;
	int m_channels = 0;
	unsigned char* m_data = nullptr;
};
