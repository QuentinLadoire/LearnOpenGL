#pragma once

class Entity;

class Component
{
	public:
	Component(Entity& entity);
	virtual ~Component();

	const Entity& GetEntity() const;

	private:
	Entity& m_entity;
};