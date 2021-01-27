#pragma once

#include <memory>

#include <glm/glm.hpp>

enum class Primitive
{
	Quad,
	Cube,
	Plane,
	Sphere,
	Cylinder,
	Capsule
};

class Mesh
{
	public:
	Mesh();

	const unsigned int GetVertexArrayId() const;
	const unsigned int GetVerticesCount() const;
	const unsigned int GetTrianglesCount() const;
	const unsigned int GetUvCount() const;

	void UpdateBufferGPU();

	static Mesh CreateCube();
	static Mesh CreateQuad();
	static Mesh CreatePlane();
	static Mesh CreateSphere();
	static Mesh CreateCylinder();
	static Mesh CreateCapsule();
	static Mesh CreatePrimitive(Primitive primitive);

	private:
	std::unique_ptr<glm::vec3[]> m_vertices;
	std::unique_ptr<unsigned int[]> m_triangles;
	std::unique_ptr<glm::vec2[]> m_uv;

	unsigned int m_verticesCount = 0;
	unsigned int m_trianglesCount = 0;
	unsigned int m_uvCount = 0;

	unsigned int m_VAO = 0;
	unsigned int m_VBO = 0;
	unsigned int m_EBO = 0;
};
