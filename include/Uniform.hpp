#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

template <typename T>
struct Uniform
{
	public:
	int id = 0;
	const char* name;
	T value;
};

using UniformMat4 = Uniform<glm::mat4>;
using UniformVec4 = Uniform<glm::vec4>;