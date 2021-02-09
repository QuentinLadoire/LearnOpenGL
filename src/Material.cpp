
#include "Material.hpp"

Shader* Material::GetShader() const
{
	return m_shader;
}
void Material::SetShader(Shader* shader)
{
	m_shader = shader;
}
