
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
#include "Entity.hpp"

int main()
{
	Window::Init(600, 600, "LearnOpenGL");
	Window::SetClearColor(0.2f, 0.3f, 0.3f);

	Shader shader = Shader("E:/CppProject/LearnOpenGL/data/Shaders/simple.vert", "E:/CppProject/LearnOpenGL/data/Shaders/simple.frag");

	Mesh cubeMesh = Mesh::CreatePrimitive(Primitive::Cube);

	Entity entity;
	MeshRenderer& renderer = entity.AddComponent<MeshRenderer>();
	renderer.SetMesh(&cubeMesh);
	renderer.SetShader(&shader);

	Image image = Image("E:/CppProject/LearnOpenGL/data/Textures/container.jpg");
	
	Texture texture = Texture();
	texture.LoadFromImage(image);

	while (Window::IsOpen())
	{
		Window::PoolEvents();

		Window::Clear();

		Window::Display();
	}

	Window::Destroy();
	return 0;
}

/*int main()
{
	Window::Init(600, 600, "LearnOpenGL");
	Window::SetClearColor(0.2f, 0.3f, 0.3f);

	Shader shader = Shader("E:/CppProject/LearnOpenGL/data/Shaders/simple.vert", "E:/CppProject/LearnOpenGL/data/Shaders/simple.frag");

	Texture container("E:/CppProject/LearnOpenGL/data/Textures/container.jpg");
	Texture awesomeFace("E:/CppProject/LearnOpenGL/data/Textures/awesomeface.png");

	float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	shader.Use();
	shader.SetInt("texture1", 0);
	shader.SetInt("texture2", 1);

	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	//glm::mat4 view = glm::mat4(1.0f);
	//// note that we're translating the scene in the reverse direction of where we want to move
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	const float cameraSpeed = 0.05f;
	
	while (Window::IsOpen())
	{
		Window::PoolEvents();

		if (Window::IsKeyPress(KeyCode::L))
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		if (Window::IsKeyPress(KeyCode::M))
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		if (Window::IsKeyPress(KeyCode::W))
			cameraPos += cameraSpeed * cameraFront;
		if (Window::IsKeyPress(KeyCode::S))
			cameraPos -= cameraSpeed * cameraFront;
		if (Window::IsKeyPress(KeyCode::A))
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		if (Window::IsKeyPress(KeyCode::D))
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

		//model = glm::rotate(model, 0.05f * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		unsigned int modelLoc = glGetUniformLocation(shader.GetId(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		unsigned int viewLoc = glGetUniformLocation(shader.GetId(), "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		unsigned int projectionLoc = glGetUniformLocation(shader.GetId(), "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		Window::Clear();

		shader.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, container.GetId());
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, awesomeFace.GetId());

		glBindVertexArray(VAO);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		Window::Display();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	Window::Destroy();

	return 0;
}*/
