#pragma once

#include <memory>

class Scene;

class SceneManager
{
	public:
	static Scene& LoadScene(std::unique_ptr<Scene> scene);

	static void Start();
	static void Update();

	private:
	SceneManager() = default;

	std::unique_ptr<Scene> m_currentScene;

	private:
	static SceneManager m_instance;
};
