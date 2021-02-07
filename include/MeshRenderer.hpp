#pragma once

#include <glm/glm.hpp>

#include "Component.hpp"

class Mesh;
class Shader;

class MeshRenderer : public Component
{
	public:
	MeshRenderer(Entity& entity);

	const Mesh* GetMesh() const;
	const Shader* GetShader() const;
	const glm::vec4 GetColor() const;

	void SetMesh(Mesh* mesh);
	void SetShader(Shader* shader);
	void SetColor(glm::vec4 color);

	void Draw();

	private:
	Mesh* m_mesh = nullptr;
	Shader* m_shader = nullptr;
	glm::vec4 m_color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
};
