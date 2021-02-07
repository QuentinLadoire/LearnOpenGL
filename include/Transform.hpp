#pragma once

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Component.hpp"

class Transform : public Component
{
	public:
	Transform(Entity& entity);

	const glm::vec3 GetPosition() const;
	const glm::quat GetRotation() const;
	const glm::vec3 GetLocalScale() const;
	const glm::vec3 GetEulerAngle() const;

	const glm::vec3 GetForward() const;
	const glm::vec3 GetBackward() const;
	const glm::vec3 GetRight() const;
	const glm::vec3 GetLeft() const;
	const glm::vec3 GetUp() const;
	const glm::vec3 GetDown() const;

	void SetPosition(glm::vec3 position);
	void SetRotation(glm::quat rotation);
	void SetLocalScale(glm::vec3 localScale);
	void SetEulerAngle(glm::vec3 eulerAngle);

	const glm::mat4 GetLocalToWorldMatrix() const;

	std::string ToString();

	private:
	glm::vec3 m_position = glm::zero<glm::vec3>();
	glm::quat m_rotation = glm::identity<glm::quat>();
	glm::vec3 m_localScale = glm::one<glm::vec3>();
};