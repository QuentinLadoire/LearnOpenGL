
#include "Asset.hpp"

Asset::Asset(const std::string& name) :
	m_name{ name }
{}
Asset::Asset(Asset&& move) noexcept
{
	m_name = std::move(move.m_name);
}

const std::string Asset::GetName() const
{
	return m_name;
}
