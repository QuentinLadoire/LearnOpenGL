#pragma once

#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include <iostream>

#include "Component.hpp"

class Entity
{
	public:
	const Component& AddComponent(std::unique_ptr<Component>&& component);

	template <typename T>
	const T& AddComponent();

	template <typename T>
	const T* GetComponent() const;

	private:
	std::vector<std::unique_ptr<Component>> m_components;
};

template <typename T>
const T& Entity::AddComponent()
{
	static_assert(std::is_base_of<Component, T>::value, "The class is not derived of component.");

	Component& component = const_cast<Component&>(AddComponent(std::make_unique<T>(*this)));
	
	return static_cast<T&>(component);
}

template <typename T>
const T* Entity::GetComponent() const
{
	static_assert(std::is_base_of<Component, T>::value, "The class is not derived of component.");

	for (auto& component : m_components)
	{
		T* tmp = dynamic_cast<T*>(component.get());
		if (tmp != nullptr)
			return tmp;
	}

	return nullptr;
}
