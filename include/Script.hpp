#pragma once

#include "Component.hpp"

class Entity;

class Script : public Component
{
	public:
	Script(Entity& entity);
	virtual void Start();
	virtual void Update();
};
