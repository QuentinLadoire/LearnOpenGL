
#include "DataManager.hpp"

DataManager DataManager::m_instance = DataManager();

Asset& DataManager::Add(const std::string& name, std::unique_ptr<Asset> asset)
{
	auto& toReturn = *(asset.get());

	m_instance.m_assets[name] = std::move(asset);

	return toReturn;
}
Asset& DataManager::Get(const std::string& name)
{
	return *(m_instance.m_assets[name]);
}
bool DataManager::Exist(const std::string& name)
{
	return m_instance.m_assets.find(name) != m_instance.m_assets.end();
}
