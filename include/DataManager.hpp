#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <type_traits>

#include "Asset.hpp"

class DataManager
{
	public:
	template <typename T>
	static T& Find(const std::string& name);

	private:
	static Asset& Add(const std::string& name, std::unique_ptr<Asset> asset);
	static Asset& Get(const std::string& name);
	static bool Exist(const std::string& name);

	DataManager() = default;

	private:
	std::unordered_map<std::string, std::unique_ptr<Asset>> m_assets{};

	private:
	static DataManager m_instance;
};

template <typename T>
T& DataManager::Find(const std::string& name)
{
	static_assert(std::is_base_of<Asset, T>::value, "The class is not derived of component.");

	if (!Exist(name))
		return static_cast<T&>(Add(name, std::make_unique<T>(name)));

	return static_cast<T&>(Get(name));
}
