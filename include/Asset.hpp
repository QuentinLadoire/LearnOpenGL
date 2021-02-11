#pragma once

#include <string>

class Asset
{
	public:
	Asset(const std::string& name);
	Asset(Asset&& move) noexcept;
	virtual ~Asset() = default;

	const std::string GetName() const;

	private:
	std::string m_name = "NoName";
};
