
#include "MeshRenderer.hpp"

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

#include "Mesh.hpp"
#include "Shader.hpp"

void MeshRenderer::SetMesh(Mesh* mesh)
{
	m_mesh = mesh;
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