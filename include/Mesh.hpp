#pragma once

#include "Asset.hpp"

#include <string>
#include <memory>
#include <type_traits>

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

class Mesh : public Asset
{
	public:
	Mesh(const std::string& name);
	Mesh(Mesh&& move) noexcept;
	~Mesh();

	const unsigned int GetVertexArrayId() const;
	const unsigned int GetVerticesCount() const;
	const unsigned int GetTrianglesCount() const;
	const unsigned int GetUvCount() const;

	void UpdateBufferGPU();

	static Mesh CreatePrimitive(Primitive primitive);

	private:
	static Mesh CreateQuad();
	static Mesh CreateCube();
	static Mesh CreatePlane();
	static Mesh CreateSphere();
	static Mesh CreateCylinder();
	static Mesh CreateCapsule();

	private:
	std::unique_ptr<float[]> m_vertices;
	std::unique_ptr<unsigned int[]> m_triangles;
	std::unique_ptr<float[]> m_uv;

	unsigned int m_verticesCount = 0;
	unsigned int m_trianglesCount = 0;
	unsigned int m_uvCount = 0;

	unsigned int m_VAO = 0;
	unsigned int m_VBO = 0;
	unsigned int m_EBO = 0;
};
