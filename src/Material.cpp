
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

