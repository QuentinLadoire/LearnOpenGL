
#include "Scene.hpp"

#include "MeshRenderer.hpp"
#include "Script.hpp"

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
	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		MeshRenderer* renderer = (*it)->GetComponent<MeshRenderer>();
		if (renderer != nullptr)
			m_renderers.push_back(renderer);

		Script* script = (*it)->GetComponent<Script>();
		if (script != nullptr)
			m_scripts.push_back(script);
	}

	for (auto it = m_scripts.begin(); it != m_scripts.end(); it++)
		(*it)->Start();
}
void Scene::Update()
{
	for (auto it = m_scripts.begin(); it != m_scripts.end(); it++)
		(*it)->Update();

	for (auto it = m_renderers.begin(); it != m_renderers.end(); it++)
		(*it)->Draw();
}
