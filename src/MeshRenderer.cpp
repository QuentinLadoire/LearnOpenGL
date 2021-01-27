
#include "MeshRenderer.hpp"

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

#include "Mesh.hpp"
#include "Shader.hpp"

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

void MeshRenderer::SetMesh(Mesh* mesh)
{
	m_mesh = mesh;
}
void MeshRenderer::SetShader(Shader* shader)
{
	m_shader = shader;
}

void MeshRenderer::Draw()
{
	if (m_shader != nullptr && m_mesh != nullptr)
	{
		m_shader->Use();

		glBindVertexArray(m_mesh->GetVertexArrayId());
		glDrawElements(GL_TRIANGLES, m_mesh->GetTrianglesCount(), GL_UNSIGNED_INT, 0);
	}
}