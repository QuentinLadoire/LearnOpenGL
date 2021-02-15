
#include "Transform.hpp"

Transform::Transform(Entity& entity) : Component(entity)
{}

const glm::vec3 Transform::GetPosition() const
{
	return m_position;
}
const glm::quat Transform::GetRotation() const
{
	return m_rotation;
}
const glm::vec3 Transform::GetLocalScale() const
{
	return m_localScale;
}
const glm::vec3 Transform::GetEulerAngle() const
{
	glm::vec3 euler = glm::eulerAngles(m_rotation);
	euler.x = glm::degrees(euler.x);
	euler.y = glm::degrees(euler.y);
	euler.z = glm::degrees(euler.z);

	return euler;
}

const glm::vec3 Transform::GetForward() const 
{
	return GetLocalToWorldMatrix() * glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
}
const glm::vec3 Transform::GetRight() const
{
	return GetLocalToWorldMatrix() * glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
}
const glm::vec3 Transform::GetUp() const
{
	return GetLocalToWorldMatrix() * glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
}

void Transform::SetPosition(glm::vec3 position)
{
	m_position = position;
}
void Transform::SetRotation(glm::quat rotation)
{
	m_rotation = rotation;
}
void Transform::SetLocalScale(glm::vec3 localScale)
{
	m_localScale = localScale;
}
void Transform::SetEulerAngle(glm::vec3 eulerAngle)
{
	eulerAngle.x = glm::radians(eulerAngle.x);
	eulerAngle.y = glm::radians(eulerAngle.y);
	eulerAngle.z = glm::radians(eulerAngle.z);
	m_rotation = glm::quat(eulerAngle);
}

const glm::mat4 Transform::GetLocalToWorldMatrix() const
{
	glm::mat4 identity = glm::identity<glm::mat4>();

	glm::mat4 translate = glm::translate(identity, m_position);
	glm::mat4 rotation = glm::mat4_cast(m_rotation);
	glm::mat4 scale = glm::scale(identity, m_localScale);

	return translate * rotation * scale;
}

std::string Transform::ToString()
{
	return std::string("Position : ") + 
		              std::to_string(m_position.x) + std::string(", ") + std::to_string(m_position.y) + std::string(", ") + std::to_string(m_position.z) + std::string("\n") +
		   std::string("Rotation : ") +
		              std::to_string(m_rotation.x) + std::string(", ") + std::to_string(m_rotation.y) + std::string(", ") + std::to_string(m_rotation.z) + std::string(", ") + std::to_string(m_rotation.w) + std::string("\n") +
		   std::string("LocalScale : ") +
		              std::to_string(m_localScale.x) + std::string(", ") + std::to_string(m_localScale.y) + std::string(", ") + std::to_string(m_localScale.z);
}
