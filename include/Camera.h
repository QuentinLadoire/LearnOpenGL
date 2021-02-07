#pragma once

#include "Component.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform;

enum class CameraType
{
	Orthographic,
	Perspective
};

class Camera : public Component
{
	public:
	static Camera* GetMainCamera();

	private:
	static Camera* m_mainCamera;

	public:
	Camera(Entity& entity);

	const glm::mat4 GetProjectionMatrix();
	const glm::mat4 GetViewMatrix();

	private:
	CameraType m_type = CameraType::Perspective;
};
