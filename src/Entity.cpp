
#include "Entity.hpp"
#include "Transform.hpp"

Entity::Entity() :
	m_transform{ AddComponent<Transform>() }
{}

Component& Entity::AddComponent(std::unique_ptr<Component>&& component)
{
	if (component == nullptr)
		throw std::runtime_error{ "ERROR - Entity : The component was nullptr." };

	m_components.push_back(std::move(component));

	return *(m_components[m_components.size() - 1].get());
}