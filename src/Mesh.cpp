
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
	m_normalsCount = move.m_normalsCount;

	m_vertices = std::move(move.m_vertices);
	m_triangles = std::move(move.m_triangles);
	m_uv = std::move(move.m_uv);
	m_normals = std::move(move.m_normals);

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
const unsigned int Mesh::GetNormalsCount() const
{
	return m_normalsCount;
}

void Mesh::UpdateBufferGPU()
{
	auto count = m_verticesCount + m_normalsCount;
	float* vertices = new float[count];
	std::memcpy(vertices, m_vertices.get(), m_verticesCount * sizeof(float));
	std::memcpy(vertices + m_verticesCount, m_normals.get(), m_normalsCount * sizeof(float));

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_trianglesCount, m_triangles.get(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)m_verticesCount);
	glEnableVertexAttribArray(1);
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
	
	cube.m_verticesCount = 72;
	cube.m_trianglesCount = 36;
	cube.m_normalsCount = 72;

	cube.m_vertices = std::make_unique<float[]>(cube.m_verticesCount);
	cube.m_triangles = std::make_unique<unsigned int[]>(cube.m_trianglesCount);
	cube.m_normals = std::make_unique<float[]>(cube.m_normalsCount);

	/*                 X                            Y                            Z     */

	/*Back Face*/
	cube.m_vertices[0] = -0.5f; cube.m_vertices[1 ] = -0.5f; cube.m_vertices[2 ] = -0.5f;
	cube.m_vertices[3] =  0.5f; cube.m_vertices[4 ] = -0.5f; cube.m_vertices[5 ] = -0.5f;
	cube.m_vertices[6] = -0.5f; cube.m_vertices[7 ] =  0.5f; cube.m_vertices[8 ] = -0.5f;
	cube.m_vertices[9] =  0.5f; cube.m_vertices[10] =  0.5f; cube.m_vertices[11] = -0.5f;

	cube.m_triangles[0] = 0; cube.m_triangles[1] = 1; cube.m_triangles[2] = 2;
	cube.m_triangles[3] = 2; cube.m_triangles[4] = 1; cube.m_triangles[5] = 3;

	cube.m_normals[0] = 0.0f; cube.m_normals[1 ] = 0.0f; cube.m_normals[2 ] = -1.0f;
	cube.m_normals[3] = 0.0f; cube.m_normals[4 ] = 0.0f; cube.m_normals[5 ] = -1.0f;
	cube.m_normals[6] = 0.0f; cube.m_normals[7 ] = 0.0f; cube.m_normals[8 ] = -1.0f;
	cube.m_normals[9] = 0.0f; cube.m_normals[10] = 0.0f; cube.m_normals[11] = -1.0f;

	/*Right Face*/
	cube.m_vertices[12] =  0.5f; cube.m_vertices[13] = -0.5f; cube.m_vertices[14] = -0.5f;
	cube.m_vertices[15] =  0.5f; cube.m_vertices[16] = -0.5f; cube.m_vertices[17] =  0.5f;
	cube.m_vertices[18] =  0.5f; cube.m_vertices[19] =  0.5f; cube.m_vertices[20] = -0.5f;
	cube.m_vertices[21] =  0.5f; cube.m_vertices[22] =  0.5f; cube.m_vertices[23] =  0.5f;

	cube.m_triangles[6] = 4; cube.m_triangles[7 ] = 5; cube.m_triangles[8 ] = 6;
	cube.m_triangles[9] = 6; cube.m_triangles[10] = 5; cube.m_triangles[11] = 7;

	cube.m_normals[12] = 1.0f; cube.m_normals[13] = 0.0f; cube.m_normals[14] = 0.0f;
	cube.m_normals[15] = 1.0f; cube.m_normals[16] = 0.0f; cube.m_normals[17] = 0.0f;
	cube.m_normals[18] = 1.0f; cube.m_normals[19] = 0.0f; cube.m_normals[20] = 0.0f;
	cube.m_normals[21] = 1.0f; cube.m_normals[22] = 0.0f; cube.m_normals[23] = 0.0f;

	/*Front Face*/
	cube.m_vertices[24] =  0.5f; cube.m_vertices[25] = -0.5f; cube.m_vertices[26] =  0.5f;
	cube.m_vertices[27] = -0.5f; cube.m_vertices[28] = -0.5f; cube.m_vertices[29] =  0.5f;
	cube.m_vertices[30] =  0.5f; cube.m_vertices[31] =  0.5f; cube.m_vertices[32] =  0.5f;
	cube.m_vertices[33] = -0.5f; cube.m_vertices[34] =  0.5f; cube.m_vertices[35] =  0.5f;

	cube.m_triangles[12] =  8; cube.m_triangles[13] = 9; cube.m_triangles[14] = 10;
	cube.m_triangles[15] = 10; cube.m_triangles[16] = 9; cube.m_triangles[17] = 11;

	cube.m_normals[24] = 0.0f; cube.m_normals[25] = 0.0f; cube.m_normals[26] = 1.0f;
	cube.m_normals[27] = 0.0f; cube.m_normals[28] = 0.0f; cube.m_normals[29] = 1.0f;
	cube.m_normals[30] = 0.0f; cube.m_normals[31] = 0.0f; cube.m_normals[32] = 1.0f;
	cube.m_normals[33] = 0.0f; cube.m_normals[34] = 0.0f; cube.m_normals[35] = 1.0f;

	/*Left Face*/
	cube.m_vertices[36] = -0.5f; cube.m_vertices[37] = -0.5f; cube.m_vertices[38] =  0.5f;
	cube.m_vertices[39] = -0.5f; cube.m_vertices[40] = -0.5f; cube.m_vertices[41] = -0.5f;
	cube.m_vertices[42] = -0.5f; cube.m_vertices[43] =  0.5f; cube.m_vertices[44] =  0.5f;
	cube.m_vertices[45] = -0.5f; cube.m_vertices[46] =  0.5f; cube.m_vertices[47] = -0.5f;

	cube.m_triangles[18] = 12; cube.m_triangles[19] = 13; cube.m_triangles[20] = 14;
	cube.m_triangles[21] = 14; cube.m_triangles[22] = 13; cube.m_triangles[23] = 15;

	cube.m_normals[36] = -1.0f; cube.m_normals[37] = 0.0f; cube.m_normals[38] = 0.0f;
	cube.m_normals[39] = -1.0f; cube.m_normals[40] = 0.0f; cube.m_normals[41] = 0.0f;
	cube.m_normals[42] = -1.0f; cube.m_normals[43] = 0.0f; cube.m_normals[44] = 0.0f;
	cube.m_normals[45] = -1.0f; cube.m_normals[46] = 0.0f; cube.m_normals[47] = 0.0f;

	/*Up Face*/
	cube.m_vertices[48] = -0.5f; cube.m_vertices[49] =  0.5f; cube.m_vertices[50] = -0.5f;
	cube.m_vertices[51] =  0.5f; cube.m_vertices[52] =  0.5f; cube.m_vertices[53] = -0.5f;
	cube.m_vertices[54] = -0.5f; cube.m_vertices[55] =  0.5f; cube.m_vertices[56] =  0.5f;
	cube.m_vertices[57] =  0.5f; cube.m_vertices[58] =  0.5f; cube.m_vertices[59] =  0.5f;

	cube.m_triangles[24] = 16; cube.m_triangles[25] = 17; cube.m_triangles[26] = 18;
	cube.m_triangles[27] = 18; cube.m_triangles[28] = 17; cube.m_triangles[29] = 19;

	cube.m_normals[48] = 0.0f; cube.m_normals[49] = 1.0f; cube.m_normals[50] = 0.0f;
	cube.m_normals[51] = 0.0f; cube.m_normals[52] = 1.0f; cube.m_normals[53] = 0.0f;
	cube.m_normals[54] = 0.0f; cube.m_normals[55] = 1.0f; cube.m_normals[56] = 0.0f;
	cube.m_normals[57] = 0.0f; cube.m_normals[58] = 1.0f; cube.m_normals[59] = 0.0f;

	/*Down Face*/
	cube.m_vertices[60] =  0.5f; cube.m_vertices[61] = -0.5f; cube.m_vertices[62] =  0.5f;
	cube.m_vertices[63] = -0.5f; cube.m_vertices[64] = -0.5f; cube.m_vertices[65] =  0.5f;
	cube.m_vertices[66] =  0.5f; cube.m_vertices[67] = -0.5f; cube.m_vertices[68] = -0.5f;
	cube.m_vertices[69] = -0.5f; cube.m_vertices[70] = -0.5f; cube.m_vertices[71] = -0.5f;

	cube.m_triangles[30] = 20; cube.m_triangles[31] = 21; cube.m_triangles[32] = 22;
	cube.m_triangles[33] = 22; cube.m_triangles[34] = 21; cube.m_triangles[35] = 23;

	cube.m_normals[60] = 0.0f; cube.m_normals[61] = -1.0f; cube.m_normals[62] = 0.0f;
	cube.m_normals[63] = 0.0f; cube.m_normals[64] = -1.0f; cube.m_normals[65] = 0.0f;
	cube.m_normals[66] = 0.0f; cube.m_normals[67] = -1.0f; cube.m_normals[68] = 0.0f;
	cube.m_normals[69] = 0.0f; cube.m_normals[70] = -1.0f; cube.m_normals[71] = 0.0f;

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