
#include "Component.hpp"

#include "Entity.hpp"
#include "Transform.hpp"

Component::Component(Entity& entity) :
	m_entity{entity},
	m_transform{entity.GetComponent<Transform>()}
{}

Component::~Component() {};


const Entity& Component::GetEntity() const
{
	return m_entity;
}

Transform* Component::GetTransform() const
{
	return m_transform;
}
