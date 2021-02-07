
#include "MeshRenderer.hpp"

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.hpp"
#include "Shader.hpp"
#include "Transform.hpp"
#include "Camera.h"
#include "Entity.hpp"

MeshRenderer::MeshRenderer(Entity& entity) :
	Component(entity)
{}

const Mesh* MeshRenderer::GetMesh() const
{
	return m_mesh;
}
const Shader* MeshRenderer::GetShader() const
{
	return m_shader;
}
const glm::vec4 MeshRenderer::GetColor() const
{
	return m_color;
}

void MeshRenderer::SetMesh(Mesh* mesh)
{
	m_mesh = mesh;
}
void MeshRenderer::SetShader(Shader* shader)
{
	m_shader = shader;
}
void MeshRenderer::SetColor(glm::vec4 color)
{
	m_color = color;
}

void MeshRenderer::Draw()
{
	if (m_shader != nullptr && m_mesh != nullptr)
	{
		m_shader->Use();

		m_shader->Set4Float("albedo", m_color.x, m_color.y, m_color.z, m_color.w);

		m_shader->SetMatrix4("model", 1, false, glm::value_ptr(GetEntity().GetComponent<Transform>()->GetLocalToWorldMatrix()));
		m_shader->SetMatrix4("view", 1, false, glm::value_ptr(Camera::GetMainCamera()->GetViewMatrix()));
		m_shader->SetMatrix4("projection", 1, false, glm::value_ptr(Camera::GetMainCamera()->GetProjectionMatrix()));

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBindVertexArray(m_mesh->GetVertexArrayId());
		glDrawElements(GL_TRIANGLES, m_mesh->GetTrianglesCount(), GL_UNSIGNED_INT, 0);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		m_shader->Set4Float("albedo", 0.0f, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, m_mesh->GetTrianglesCount(), GL_UNSIGNED_INT, 0);
	}
}