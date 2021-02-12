
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
#include "DataManager.hpp"
#include "SceneManager.hpp"
#include "Scene.hpp"

#include "Shader.hpp"
#include "Mesh.hpp"

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
void DebugLog(glm::vec3 vec3)
{
	std::cout << "Position : " << vec3.x << " - " << vec3.y << " - " << vec3.z << std::endl;
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

		GetTransform()->SetEulerAngle(glm::vec3(angle, angle, angle));
	}

	private:
	float angle = 0.0f;
};
class Tmp2 : public Script
{
	public:
	Tmp2(Entity& entity) :
		Script(entity)
	{}
	virtual void Update() override
	{
		Script::Update();

		glm::vec3 direction = glm::zero<glm::vec3>();

		if (Window::IsKeyPress(KeyCode::W))
			direction -= GetTransform()->GetForward() * glm::vec3(1.0f, 1.0f, -1.0f);
		if (Window::IsKeyPress(KeyCode::S))
			direction -= GetTransform()->GetBackward() * glm::vec3(1.0f, 1.0f, -1.0f);
		if (Window::IsKeyPress(KeyCode::D))
			direction += GetTransform()->GetRight() * glm::vec3(-1.0f, 1.0f, 1.0f);
		if (Window::IsKeyPress(KeyCode::A))
			direction += GetTransform()->GetLeft() * glm::vec3(-1.0f, 1.0f, 1.0f);
		if (Window::IsKeyPress(KeyCode::Space))
			direction += GetTransform()->GetUp() * glm::vec3(1.0f, -1.0f, 1.0f);
		if (Window::IsKeyPress(KeyCode::LeftShift))
			direction += GetTransform()->GetDown() * glm::vec3(1.0f, -1.0f, 1.0f);

		if (direction != glm::zero<glm::vec3>())
			direction = glm::normalize(direction);

		GetTransform()->SetPosition(GetTransform()->GetPosition() + (direction * 0.1f));

		if (Window::IsKeyPress(KeyCode::Q))
			angle -= 0.5f;
		if (Window::IsKeyPress(KeyCode::E))
			angle += 0.5f;

		GetTransform()->SetEulerAngle(glm::vec3(0.0f, angle, 0.0f));
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
	Shader shader("simple");
	Mesh cubeMesh = Mesh::CreatePrimitive(Primitive::Cube);

	//Entity
	{
		for (int i = 0; i < 1; i++)
		{
			Entity& entity = scene.AddEntity();
			//entity.GetTransform().SetPosition(glm::vec3((rand() % 5) - 2.5f, (rand() % 5) - 2.5f, (rand() % 5) - 2.5f));
			entity.AddComponent<Tmp>();
			MeshRenderer& renderer = entity.AddComponent<MeshRenderer>();
			renderer.SetColor(glm::vec4(1.0f, 0.5f, 0.3f, 1.0f));
			renderer.SetMesh(&cubeMesh);
			renderer.SetShader(&shader);
		}

		Entity& cameraEntity = scene.AddEntity();
		cameraEntity.GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
		cameraEntity.AddComponent<Camera>();
		cameraEntity.AddComponent<Tmp2>();
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
