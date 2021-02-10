#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <json/json.h>

#include "Uniform.hpp"

class Shader;
class Texture;

class Material
{
	public:
	static const char* Path;

	public:
	Shader* GetShader() const;
	void SetShader(Shader* shader);

	private:
	Shader* m_shader = nullptr;
};