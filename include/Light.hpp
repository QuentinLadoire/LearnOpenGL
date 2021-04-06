#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.hpp"

class Light : public Component
{
	public:
	static Light* GetMainLight() { return m_instance; }

	public:
	Light(Entity& entity);

	glm::vec4 GetColor();
	void SetColor(glm::vec4 color);

	private:
	glm::vec4 m_color = glm::one<glm::vec4>();

	private:
	static Light* m_instance;
};
