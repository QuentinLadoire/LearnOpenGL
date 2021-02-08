#pragma once

#include <vector>
#include <memory>

#include "Entity.hpp"

class MeshRenderer;

class Scene
{
	public:
	Entity& AddEntity();
	void RemoveEntity(Entity& entity);

	private:
	std::vector<std::unique_ptr<Entity>> m_entities{};
};
