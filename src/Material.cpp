
#include "Material.hpp"

#include <iostream>
#include <fstream>

#include "Shader.hpp"

const char* Material::Path = "data/Materials/";

Shader* Material::GetShader() const
{
	return m_shader;
}
void Material::SetShader(Shader* shader)
{
	m_shader = shader;
}

void Material::SetVec4(std::string name, glm::vec4 value)
{
	for (auto it = m_uniformsVec4.begin(); it != m_uniformsVec4.end(); it++)
		if (it->name == name)
		{
			it->value = value;
			return;
		}

	m_uniformsVec4.push_back(UniformVec4{ m_shader->GetUniformId(name), name.c_str(), value });
}
void Material::SetMat4(std::string name, glm::mat4 value)
{
	for (auto it = m_uniformsMat4.begin(); it != m_uniformsMat4.end(); it++)
		if (it->name == name)
		{
			it->value = value;
			return;
		}

	m_uniformsMat4.push_back(UniformMat4{ m_shader->GetUniformId(name), name.c_str(), value });
}

void Material::Use()
{
	m_shader->Use();

	for (auto it = m_uniformsMat4.begin(); it != m_uniformsMat4.end(); it++)
		m_shader->SetMatrix4(it->id, 1, false, glm::value_ptr(it->value));

	for (auto it = m_uniformsVec4.begin(); it != m_uniformsVec4.end(); it++)
		m_shader->Set4Float(it->id, it->value.x, it->value.y, it->value.z, it->value.w);
}

void Material::SaveFile()
{
	std::ofstream file(Path + std::string("test.mat"), std::ios::trunc);
	if (file.is_open())
		file << Serialize();
	else
		std::cout << "Can't open the file at " << Path + std::string("test.mat") << std::endl;
}

void Material::ClearUniforms()
{
	m_uniformsMat4.clear();
	m_uniformsVec4.clear();
}
Json::String Material::Serialize()
{
	Json::Value root(Json::objectValue);
	root["shader"] = m_shader->GetName();

	Json::Value uniforms(Json::arrayValue);
	for (auto it = m_uniformsMat4.begin(); it != m_uniformsMat4.end(); it++)
	{
		Json::Value uniform(Json::objectValue);
		uniform["type"] = "mat4";
		uniform["name"] = (it)->name;
		uniform["value"] = 0;

		uniforms.append(uniform);
	}

	for (auto it = m_uniformsVec4.begin(); it != m_uniformsVec4.end(); it++)
	{
		Json::Value uniform(Json::objectValue);
		uniform["type"] = "vec4";
		uniform["name"] = (it)->name;
		uniform["value"] = 0;

		uniforms.append(uniform);
	}

	root["uniforms"] = uniforms;

	return root.toStyledString();
}
