
#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>
#include <stb_image/std_image.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <json/json.h>


#include "Window.hpp"
#include "Shader.hpp"
#include "Image.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"
#include "MeshRenderer.hpp"
#include "Camera.h"
#include "Entity.hpp"

void DebugLog(glm::mat4 matrix)
{
	std::cout << matrix[0][0] << " ; " << matrix[0][1] << " ; " << matrix[0][2] << " ; " << matrix[0][3] << std::endl;
	std::cout << matrix[1][0] << " ; " << matrix[1][1] << " ; " << matrix[1][2] << " ; " << matrix[1][3] << std::endl;
	std::cout << matrix[2][0] << " ; " << matrix[2][1] << " ; " << matrix[2][2] << " ; " << matrix[2][3] << std::endl;
	std::cout << matrix[3][0] << " ; " << matrix[3][1] << " ; " << matrix[3][2] << " ; " << matrix[3][3] << std::endl;
}

int main()
{
	Window::Init(600, 600, "LearnOpenGL");
	Window::SetClearColor(0.2f, 0.3f, 0.3f);

	Shader shader = Shader("E:/CppProject/LearnOpenGL/data/Shaders/simple.vert", "E:/CppProject/LearnOpenGL/data/Shaders/simple.frag");

	Mesh cubeMesh = Mesh::CreatePrimitive(Primitive::Cube);

	Entity entity;
	MeshRenderer& renderer = entity.AddComponent<MeshRenderer>();
	renderer.SetColor(glm::vec4(1.0f, 0.5f, 0.3f, 1.0f));
	renderer.SetMesh(&cubeMesh);
	renderer.SetShader(&shader);

	float angle = 0.0f;

	Entity cameraEntity;
	cameraEntity.GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -5.0f));
	Camera& camera = cameraEntity.AddComponent<Camera>();

	while (Window::IsOpen())
	{
		Window::PoolEvents();

		angle += 0.5f;
		if (angle > 360.0f)
			angle = 0.0f;

		entity.GetTransform().SetEulerAngle(glm::vec3(angle, angle, angle));

		Window::Clear();

		renderer.Draw();

		Window::Display();
	}

	Window::Destroy();
	return 0;
}
