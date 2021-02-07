
#include "Camera.h"

#include "Entity.hpp"
#include "Transform.hpp"

Camera* Camera::m_mainCamera = nullptr;
Camera* Camera::GetMainCamera()
{
	return m_mainCamera;
}

Camera::Camera(Entity& entity) :
	Component(entity)
{
	if (m_mainCamera == nullptr)
		m_mainCamera = this;
}

const glm::mat4 Camera::GetProjectionMatrix()
{
	switch (m_type)
	{
		case CameraType::Orthographic:
			return glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f);
			break;

		case CameraType::Perspective:
			return glm::perspective(glm::radians(45.0f), 600.0f / 600.0f, 0.1f, 100.0f);
			break;
	}
}

const glm::mat4 Camera::GetViewMatrix()
{
	return GetTransform()->GetLocalToWorldMatrix();
}
