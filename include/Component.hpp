#pragma once

class Entity;
class Transform;

class Component
{
	public:
	Component(Entity& entity);
	virtual ~Component();

	const Entity& GetEntity() const;
	Transform* GetTransform() const;

	private:
	Entity& m_entity;
	Transform* m_transform = nullptr;
};