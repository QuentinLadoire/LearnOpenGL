
#include "SceneManager.hpp"

#include "Scene.hpp"

Scene& SceneManager::LoadScene(std::unique_ptr<Scene> scene)
{
	if (m_instance.m_currentScene != nullptr)
		m_instance.m_currentScene->Unload();

	m_instance.m_currentScene = std::move(scene);

	m_instance.m_currentScene->Load();

	return *(m_instance.m_currentScene.get());
}

void SceneManager::Start()
{
	if (m_instance.m_currentScene != nullptr)
		m_instance.m_currentScene->Start();
}
void SceneManager::Update()
{
	if (m_instance.m_currentScene != nullptr)
		m_instance.m_currentScene->Update();
}
