
#include <iostream>
#include <stdlib.h>
#include <memory>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>
#include <stb_image/std_image.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <json/json.h>


#include "Window.hpp"
#include "SceneManager.hpp"
#include "Scene.hpp"

#include "Shader.hpp"
#include "Image.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"
#include "Material.hpp"

#include "Transform.hpp"
#include "MeshRenderer.hpp"
#include "Camera.hpp"
#include "Script.hpp"

#include "Entity.hpp"

void DebugLog(glm::mat4 matrix)
{
	std::cout << matrix[0][0] << " ; " << matrix[0][1] << " ; " << matrix[0][2] << " ; " << matrix[0][3] << std::endl;
	std::cout << matrix[1][0] << " ; " << matrix[1][1] << " ; " << matrix[1][2] << " ; " << matrix[1][3] << std::endl;
	std::cout << matrix[2][0] << " ; " << matrix[2][1] << " ; " << matrix[2][2] << " ; " << matrix[2][3] << std::endl;
	std::cout << matrix[3][0] << " ; " << matrix[3][1] << " ; " << matrix[3][2] << " ; " << matrix[3][3] << std::endl;
}

class Tmp : public Script
{
	public:
	Tmp(Entity& entity) :
		Script(entity)
	{}
	virtual void Update() override
	{
		Script::Update();

		angle += 0.5f;
		if (angle > 360.0f)
			angle = 0.0f;

		GetTransform()->SetEulerAngle(glm::vec3(angle, angle, angle));
	}

	private:
	float angle = 0.0f;
};

int main()
{
	Window::Init(600, 600, "LearnOpenGL");
	Window::SetClearColor(0.2f, 0.3f, 0.3f);

	srand(3);

	Scene& scene = SceneManager::LoadScene(std::make_unique<Scene>());

	//Data
	Shader shader = Shader("simple");
	Mesh cubeMesh = Mesh::CreatePrimitive(Primitive::Cube);

	Material mat;
	mat.SetShader(&shader);

	//Entity
	{
		for (int i = 0; i < 10; i++)
		{
			Entity& entity = scene.AddEntity();
			entity.GetTransform().SetPosition(glm::vec3((rand() % 5) - 2.5f, (rand() % 5) - 2.5f, (rand() % 5) - 2.5f));

			entity.AddComponent<Tmp>();
			MeshRenderer& renderer = entity.AddComponent<MeshRenderer>();
			renderer.SetColor(glm::vec4(1.0f, 0.5f, 0.3f, 1.0f));
			renderer.SetMesh(&cubeMesh);
			renderer.SetShader(&shader);
		}

		Entity& cameraEntity = scene.AddEntity();
		cameraEntity.GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
		cameraEntity.AddComponent<Camera>();
	}

	SceneManager::Start();

	while (Window::IsOpen())
	{
		Window::PoolEvents();

		Window::Clear();

		SceneManager::Update();

		Window::Display();
	}

	Window::Destroy();

	return 0;
}
