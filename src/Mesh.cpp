
#include "Mesh.hpp"

#include <iostream>

#include <glad/glad.h>
#include <glfw-3-3-2/GLFW/glfw3.h>

#include "DataManager.hpp"

Mesh::Mesh(const std::string& name) :
	Asset(name)
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
}
Mesh::Mesh(Mesh&& move) noexcept :
	Asset(std::move(move))
{
	m_verticesCount = move.m_verticesCount;
	m_trianglesCount = move.m_trianglesCount;
	m_uvCount = move.m_uvCount;

	m_vertices = std::move(move.m_vertices);
	m_triangles = std::move(move.m_triangles);
	m_uv = std::move(move.m_uv);

	m_VAO = move.m_VAO;
	m_VBO = move.m_VBO;
	m_EBO = move.m_EBO;

	move.m_VAO = 0;
	move.m_VBO = 0;
	move.m_EBO = 0;
}
Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_verticesCount, m_vertices.get(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_trianglesCount, m_triangles.get(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

Mesh Mesh::CreateQuad()
{
	Mesh quad = Mesh("Quad");

	quad.m_verticesCount = 4 * 3;
	quad.m_trianglesCount = 6;

	quad.m_vertices = std::make_unique<float[]>(quad.m_verticesCount);
	/*                  X                            Y                            Z     */
	quad.m_vertices[0 ] = -0.5f; quad.m_vertices[1 ] =  0.0f; quad.m_vertices[2 ] = -0.5f;
	quad.m_vertices[3 ] =  0.5f; quad.m_vertices[4 ] =  0.0f; quad.m_vertices[5 ] = -0.5f;
	quad.m_vertices[6 ] = -0.5f; quad.m_vertices[7 ] =  0.0f; quad.m_vertices[8 ] =  0.5f;
	quad.m_vertices[9 ] =  0.5f; quad.m_vertices[10] =  0.0f; quad.m_vertices[11] =  0.5f;

	quad.m_triangles = std::make_unique<unsigned int[]>(quad.m_trianglesCount);
	quad.m_triangles[0] = 0;
	quad.m_triangles[1] = 1;
	quad.m_triangles[2] = 3;

	quad.m_triangles[3] = 3;
	quad.m_triangles[4] = 2;
	quad.m_triangles[5] = 1;

	quad.UpdateBufferGPU();

	return quad;
}
Mesh Mesh::CreateCube()
{
	Mesh cube = Mesh("Cube");
	
	cube.m_verticesCount = 8 * 3;
	cube.m_trianglesCount = 36;

	cube.m_vertices = std::make_unique<float[]>(cube.m_verticesCount);
	/*                  X                            Y                            Z     */
	cube.m_vertices[0 ] = -0.5f; cube.m_vertices[1 ] = -0.5f; cube.m_vertices[2 ] = -0.5f;
	cube.m_vertices[3 ] =  0.5f; cube.m_vertices[4 ] = -0.5f; cube.m_vertices[5 ] = -0.5f;
	cube.m_vertices[6 ] = -0.5f; cube.m_vertices[7 ] =  0.5f; cube.m_vertices[8 ] = -0.5f;
	cube.m_vertices[9 ] =  0.5f; cube.m_vertices[10] =  0.5f; cube.m_vertices[11] = -0.5f;

	cube.m_vertices[12] = -0.5f; cube.m_vertices[13] = -0.5f; cube.m_vertices[14] =  0.5f;
	cube.m_vertices[15] =  0.5f; cube.m_vertices[16] = -0.5f; cube.m_vertices[17] =  0.5f;
	cube.m_vertices[18] = -0.5f; cube.m_vertices[19] =  0.5f; cube.m_vertices[20] =  0.5f;
	cube.m_vertices[21] =  0.5f; cube.m_vertices[22] =  0.5f; cube.m_vertices[23] =  0.5f;

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

	return cube;
}
Mesh Mesh::CreatePlane()
{
	return Mesh("Plane");
}
Mesh Mesh::CreateSphere()
{
	return Mesh("Sphere");
}
Mesh Mesh::CreateCylinder()
{
	return Mesh("Cylinder");
}
Mesh Mesh::CreateCapsule()
{
	return Mesh("Capsule");
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

	return CreateCube(); //never happen
}