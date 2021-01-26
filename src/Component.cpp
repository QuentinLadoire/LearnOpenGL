
#include "Component.hpp"

Component::Component(Entity& entity) :
	m_entity{entity} {}

Component::~Component() {};


const Entity& Component::GetEntity() const
{
	return m_entity;
}