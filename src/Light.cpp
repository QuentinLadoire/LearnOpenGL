
#include "Light.hpp"

Light* Light::m_instance = nullptr;

Light::Light(Entity& entity) :
	Component(entity)
{
	m_instance = this;
}

glm::vec4 Light::GetColor()
{
	return m_color;
}
void Light::SetColor(glm::vec4 color)
{
	m_color = color;
}
