#pragma once

#include "Component.hpp"

class Mesh;
class Shader;

class MeshRenderer : public Component
{
	public:
	MeshRenderer(Entity& entity);

	const Mesh* GetMesh() const;
	const Shader* GetShader() const;

	void SetMesh(Mesh* mesh);
	void SetShader(Shader* shader);

	void Draw();

	private:
	Mesh* m_mesh = nullptr;
	Shader* m_shader = nullptr;
};
