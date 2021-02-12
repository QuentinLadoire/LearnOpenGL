
#include "Material.hpp"

#include <iostream>
#include <fstream>

#include "Shader.hpp"

const char* Material::Path = "data/Materials/";

Material::Material(const std::string& name) :
	Asset(name)
{}

Shader* Material::GetShader() const
{
	return m_shader;
}
glm::vec4 Material::GetColor() const
{
	return m_color;
}

void Material::SetShader(Shader* shader)
{
	m_shader = shader;
}
void Material::SetColor(glm::vec4 color)
{
	m_color = color;
}
