
#include "Mesh.hpp"

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

Mesh::Mesh()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
}

const unsigned int Mesh::GetVertexArrayId() const
{
	return m_VAO;
}
const unsigned int Mesh::GetVerticesCount() const
{
	return m_verticesCount;
}
const unsigned int Mesh::GetTrianglesCount() const
{
	return m_trianglesCount;
}
const unsigned int Mesh::GetUvCount() const
{
	return m_uvCount;
}

void Mesh::UpdateBufferGPU()
{
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_verticesCount * 3, m_vertices.get(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_trianglesCount, m_triangles.get(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

Mesh Mesh::CreateQuad()
{
	Mesh quad{};

	quad.m_verticesCount = 4;
	quad.m_trianglesCount = 6;
	quad.m_uvCount = 4;

	quad.m_vertices = std::make_unique<glm::vec3[]>(quad.m_verticesCount);
	quad.m_vertices[0] = glm::vec3(-0.5f, 0.0f, -0.5f);
	quad.m_vertices[1] = glm::vec3(0.5f, 0.0f, -0.5f);
	quad.m_vertices[2] = glm::vec3(-0.5f, 0.0f, 0.5f);
	quad.m_vertices[3] = glm::vec3(0.5f, 0.0f, 0.5f);

	quad.m_triangles = std::make_unique<unsigned int[]>(quad.m_trianglesCount);
	quad.m_triangles[0] = 0;
	quad.m_triangles[1] = 1;
	quad.m_triangles[2] = 3;

	quad.m_triangles[3] = 3;
	quad.m_triangles[4] = 2;
	quad.m_triangles[5] = 1;

	quad.m_uv = std::make_unique<glm::vec2[]>(quad.m_uvCount);
	quad.m_uv[0] = glm::vec2(0.0f, 0.0f);
	quad.m_uv[0] = glm::vec2(1.0f, 0.0f);
	quad.m_uv[0] = glm::vec2(0.0f, 1.0f);
	quad.m_uv[0] = glm::vec2(1.0f, 1.0f);

	quad.UpdateBufferGPU();

	return quad;
}
Mesh Mesh::CreateCube()
{
	Mesh cube{};

	cube.m_verticesCount = 8;
	cube.m_trianglesCount = 36;

	cube.m_vertices = std::make_unique<glm::vec3[]>(cube.m_verticesCount);
	cube.m_vertices[0] = glm::vec3(-0.5f, -0.5f, -0.5f);
	cube.m_vertices[1] = glm::vec3( 0.5f, -0.5f, -0.5f);
	cube.m_vertices[2] = glm::vec3(-0.5f,  0.5f, -0.5f);
	cube.m_vertices[3] = glm::vec3( 0.5f,  0.5f, -0.5f);

	cube.m_vertices[4] = glm::vec3(-0.5f, -0.5f,  0.5f);
	cube.m_vertices[5] = glm::vec3( 0.5f, -0.5f,  0.5f);
	cube.m_vertices[6] = glm::vec3(-0.5f,  0.5f,  0.5f);
	cube.m_vertices[7] = glm::vec3( 0.5f,  0.5f,  0.5f);

	cube.m_triangles = std::make_unique<unsigned int[]>(cube.m_trianglesCount);
	cube.m_triangles[0 ] = 0;
	cube.m_triangles[1 ] = 1;
	cube.m_triangles[2 ] = 2;
					 
	cube.m_triangles[3 ] = 2;
	cube.m_triangles[4 ] = 1;
	cube.m_triangles[5 ] = 3;
					 
	cube.m_triangles[6 ] = 1;
	cube.m_triangles[7 ] = 5;
	cube.m_triangles[8 ] = 3;
					 
	cube.m_triangles[9 ] = 3;
	cube.m_triangles[10] = 5;
	cube.m_triangles[11] = 7;

	cube.m_triangles[12] = 5;
	cube.m_triangles[13] = 4;
	cube.m_triangles[14] = 7;

	cube.m_triangles[15] = 7;
	cube.m_triangles[16] = 4;
	cube.m_triangles[17] = 6;

	cube.m_triangles[18] = 4;
	cube.m_triangles[19] = 0;
	cube.m_triangles[20] = 6;

	cube.m_triangles[21] = 6;
	cube.m_triangles[22] = 0;
	cube.m_triangles[23] = 2;

	cube.m_triangles[24] = 2;
	cube.m_triangles[25] = 3;
	cube.m_triangles[26] = 6;

	cube.m_triangles[27] = 6;
	cube.m_triangles[28] = 3;
	cube.m_triangles[29] = 7;

	cube.m_triangles[30] = 1;
	cube.m_triangles[31] = 0;
	cube.m_triangles[32] = 5;

	cube.m_triangles[33] = 5;
	cube.m_triangles[34] = 0;
	cube.m_triangles[35] = 4;

	cube.UpdateBufferGPU();

	return Mesh();
}
Mesh Mesh::CreatePlane()
{
	return Mesh();
}
Mesh Mesh::CreateSphere()
{
	return Mesh();
}
Mesh Mesh::CreateCylinder()
{
	return Mesh();
}
Mesh Mesh::CreateCapsule()
{
	return Mesh();
}
Mesh Mesh::CreatePrimitive(Primitive primitive)
{
	switch (primitive)
	{
		case Primitive::Quad:
			return CreateQuad();
		case Primitive::Cube:
			return CreateCube();
		case Primitive::Plane:
			return CreatePlane();
		case Primitive::Sphere:
			return CreateSphere();
		case Primitive::Cylinder:
			return CreateCylinder();
		case Primitive::Capsule:
			return CreateCapsule();
	}

	return Mesh();
}