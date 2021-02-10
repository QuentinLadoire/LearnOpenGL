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

	void SetVec4(std::string name, glm::vec4 value);
	void SetMat4(std::string name, glm::mat4 value);

	void Use();

	void SaveFile();

	private:
	void ClearUniforms();
	Json::String Serialize();

	private:
	Shader* m_shader = nullptr;

	std::vector<UniformMat4> m_uniformsMat4{};
	std::vector<UniformVec4> m_uniformsVec4{};
};