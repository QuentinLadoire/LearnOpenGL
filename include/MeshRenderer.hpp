#pragma once

#include "Component.hpp"

class Mesh;
class Shader;

class MeshRenderer : public Component
{
	public:
	void SetMesh(Mesh* mesh);

	void Draw();

	private:
	Mesh* m_mesh = nullptr;
	Shader* m_shader = nullptr;
};
