#pragma once

#include <vector>

class Shader;
class Texture;

class Material
{
	public:
	Shader* GetShader() const;
	void SetShader(Shader* shader);

	private:
	Shader* m_shader = nullptr;


};