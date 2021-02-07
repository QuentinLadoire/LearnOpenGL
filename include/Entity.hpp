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
	Entity();

	Component& AddComponent(std::unique_ptr<Component>&& component);

	Transform& GetTransform() const;

	template <typename T>
	T& AddComponent();

	template <typename T>
	T* GetComponent() const;

	private:
	std::vector<std::unique_ptr<Component>> m_components;
	class Transform& m_transform;
};

template <typename T>
T& Entity::AddComponent()
{
	static_assert(std::is_base_of<Component, T>::value, "The class is not derived of component.");

	Component& component = AddComponent(std::make_unique<T>(*this));
	
	return static_cast<T&>(component);
}

template <typename T>
T* Entity::GetComponent() const
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
