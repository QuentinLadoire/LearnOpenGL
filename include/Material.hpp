#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <json/json.h>

#include "Uniform.hpp"

#include "Asset.hpp"

class Shader;
class Texture;

class Material : public Asset
{
	public:
	static const char* Path;

	public:
	Material(const std::string& name);

	Shader* GetShader() const;
	glm::vec4 GetColor() const;

	void SetShader(Shader* shader);
	void SetColor(glm::vec4 color);

	private:
	Shader* m_shader = nullptr;
	glm::vec4 m_color = glm::one<glm::vec4>();
};