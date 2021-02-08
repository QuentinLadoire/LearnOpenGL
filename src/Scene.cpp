
#include "Scene.hpp"

Entity& Scene::AddEntity()
{
	m_entities.push_back(std::make_unique<Entity>());

	return *(m_entities[m_entities.size() - 1].get());
}
void Scene::RemoveEntity(Entity& entity)
{
	auto it = m_entities.begin();
	for (; it != m_entities.end(); it++)
		if (it->get() == &entity)
			break;

	m_entities.erase(it);
}

void Scene::Load()
{

}
void Scene::Unload()
{

}

void Scene::Start()
{

}
void Scene::Update()
{

}
