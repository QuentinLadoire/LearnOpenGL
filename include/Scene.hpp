#pragma once

#include <vector>
#include <memory>

#include "Entity.hpp"

class Scene
{
	public:
	Entity& AddEntity();
	void RemoveEntity(Entity& entity);

	void Load();
	void Unload();

	void Start();
	void Update();

	private:
	std::vector<std::unique_ptr<Entity>> m_entities{};
};
