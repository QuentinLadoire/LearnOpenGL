
#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

Shader::Shader(const std::string vertexPath, const std::string fragmentPath)
{
	std::string vertexString;
	std::string fragmentString;

	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertexShaderFile.open(vertexPath);
		fragmentShaderFile.open(fragmentPath);

		std::stringstream vertexStream;
		std::stringstream fragmentStream;

		vertexStream << vertexShaderFile.rdbuf();
		fragmentStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertexString = vertexStream.str();
		fragmentString = fragmentStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR - Shader : File not succesfully read" << std::endl << "Shader Path : " << vertexPath << std::endl << "              " << fragmentPath << std::endl;
	}

	const char* vertexCode = vertexString.c_str();
	const char* fragmentCode = fragmentString.c_str();

	unsigned int vertexId;
	unsigned int fragmentId;
	int success;
	char infoLog[512];

	vertexId = glCreateShader(GL_VERTEX_SHADER);
	fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexId, 1, &vertexCode, NULL);
	glShaderSource(fragmentId, 1, &fragmentCode, NULL);

	glCompileShader(vertexId);
	glCompileShader(fragmentId);

	glGetShaderiv(vertexId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexId, 512, NULL, infoLog);
		std::cout << "ERROR - Shader : Vertex Compilation Failed" << std::endl << infoLog << std::endl;
	}
	glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentId, 512, NULL, infoLog);
		std::cout << "Error - Shader : Fragment Compilation Failed" << std::endl << infoLog << std::endl;
	}

	m_id = glCreateProgram();
	glAttachShader(m_id, vertexId);
	glAttachShader(m_id, fragmentId);
	glLinkProgram(m_id);

	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_id, 512, NULL, infoLog);
		std::cout << "ERROR - Shader : Program Linking Failed" << std::endl << infoLog << std::endl;
	}

	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);
}
Shader::~Shader()
{
	glDeleteProgram(m_id);
}

void Shader::Use() const
{
	glUseProgram(m_id);
}

void Shader::SetBool(const int id, bool value) const
{
	glUseProgram(m_id);
	glUniform1i(id, (int)value);
}
void Shader::SetBool(const std::string& name, bool value) const
{
	glUseProgram(m_id);
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
}

void Shader::SetFloat(const int id, float value) const
{
	glUseProgram(m_id);
	glUniform1f(id, value);
}
void Shader::SetFloat(const std::string& name, float value) const
{
	glUseProgram(m_id);
	glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}
void Shader::Set2Float(const int id, float value1, float value2) const
{
	glUseProgram(m_id);
	glUniform2f(id, value1, value2);
}
void Shader::Set2Float(const std::string& name, float value1, float value2) const
{
	glUseProgram(m_id);
	glUniform2f(glGetUniformLocation(m_id, name.c_str()), value1, value2);
}
void Shader::Set3Float(const int id, float value1, float value2, float value3) const
{
	glUseProgram(m_id);
	glUniform3f(id, value1, value2, value3);
}
void Shader::Set3Float(const std::string& name, float value1, float value2, float value3) const
{
	glUseProgram(m_id);
	glUniform3f(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3);
}
void Shader::Set4Float(const int id, float value1, float value2, float value3, float value4) const
{
	glUseProgram(m_id);
	glUniform4f(id, value1, value2, value3, value4);
}
void Shader::Set4Float(const std::string& name, float value1, float value2, float value3, float value4) const
{
	glUseProgram(m_id);
	glUniform4f(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3, value4);
}

void Shader::SetInt(const int id, int value) const
{
	glUseProgram(m_id);
	glUniform1i(id, value);
}
void Shader::SetInt(const std::string& name, int value) const
{
	glUseProgram(m_id);
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}
void Shader::Set2Int(const int id, int value1, int value2) const
{
	glUseProgram(m_id);
	glUniform2i(id, value1, value2);
}
void Shader::Set2Int(const std::string& name, int value1, int value2) const
{
	glUseProgram(m_id);
	glUniform2i(glGetUniformLocation(m_id, name.c_str()), value1, value2);
}
void Shader::Set3Int(const int id, int value1, int value2, int value3) const
{
	glUseProgram(m_id);
	glUniform3i(id, value1, value2, value3);
}
void Shader::Set3Int(const std::string& name, int value1, int value2, int value3) const
{
	glUseProgram(m_id);
	glUniform3i(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3);
}
void Shader::Set4Int(const int id, int value1, int value2, int value3, int value4) const
{
	glUseProgram(m_id);
	glUniform4i(id, value1, value2, value3, value4);
}
void Shader::Set4Int(const std::string& name, int value1, int value2, int value3, int value4) const
{
	glUseProgram(m_id);
	glUniform4i(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3, value4);
}

void Shader::SetUInt(const int id, unsigned int value) const
{
	glUseProgram(m_id);
	glUniform1ui(id, value);
}
void Shader::SetUInt(const std::string& name, unsigned int value) const
{
	glUseProgram(m_id);
	glUniform1ui(glGetUniformLocation(m_id, name.c_str()), value);
}
void Shader::Set2UInt(const int id, unsigned int value1, unsigned int value2) const
{
	glUseProgram(m_id);
	glUniform2ui(id, value1, value2);
}
void Shader::Set2UInt(const std::string& name, unsigned int value1, unsigned int value2) const
{
	glUseProgram(m_id);
	glUniform2ui(glGetUniformLocation(m_id, name.c_str()), value1, value2);
}
void Shader::Set3UInt(const int id, unsigned int value1, unsigned int value2, unsigned int value3) const
{
	glUseProgram(m_id);
	glUniform3ui(id, value1, value2, value3);
}
void Shader::Set3UInt(const std::string& name, unsigned int value1, unsigned int value2, unsigned int value3) const
{
	glUseProgram(m_id);
	glUniform3ui(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3);
}
void Shader::Set4UInt(const int id, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4) const
{
	glUseProgram(m_id);
	glUniform4ui(id, value1, value2, value3, value4);
}
void Shader::Set4UInt(const std::string& name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4) const
{
	glUseProgram(m_id);
	glUniform4ui(glGetUniformLocation(m_id, name.c_str()), value1, value2, value3, value4);
}

void Shader::SetFloatArray(const int id, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform1fv(id, count, value);
}
void Shader::SetFloatArray(const std::string& name, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform1fv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set2FloatArray(const int id, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform2fv(id, count, value);
}
void Shader::Set2FloatArray(const std::string& name, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform2fv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set3FloatArray(const int id, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform3fv(id, count, value);
}
void Shader::Set3FloatArray(const std::string& name, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform3fv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set4FloatArray(const int id, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform4fv(id, count, value);
}
void Shader::Set4FloatArray(const std::string& name, int count, const float* value) const
{
	glUseProgram(m_id);
	glUniform4fv(glGetUniformLocation(m_id, name.c_str()), count, value);
}

void Shader::SetIntArray(const int id, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform1iv(id, count, value);
}
void Shader::SetIntArray(const std::string& name, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform1iv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set2IntArray(const int id, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform2iv(id, count, value);
}
void Shader::Set2IntArray(const std::string& name, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform2iv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set3IntArray(const int id, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform3iv(id, count, value);
}
void Shader::Set3IntArray(const std::string& name, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform3iv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set4IntArray(const int id, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform4iv(id, count, value);
}
void Shader::Set4IntArray(const std::string& name, int count, const int* value) const
{
	glUseProgram(m_id);
	glUniform4iv(glGetUniformLocation(m_id, name.c_str()), count, value);
}

void Shader::SetUIntArray(const int id, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform1uiv(id, count, value);
}
void Shader::SetUIntArray(const std::string& name, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform1uiv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set2UIntArray(const int id, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform2uiv(id, count, value);
}
void Shader::Set2UIntArray(const std::string& name, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform2uiv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set3UIntArray(const int id, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform3uiv(id, count, value);
}
void Shader::Set3UIntArray(const std::string& name, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform3uiv(glGetUniformLocation(m_id, name.c_str()), count, value);
}
void Shader::Set4UIntArray(const int id, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform4uiv(id, count, value);
}
void Shader::Set4UIntArray(const std::string& name, int count, const unsigned int* value) const
{
	glUseProgram(m_id);
	glUniform4uiv(glGetUniformLocation(m_id, name.c_str()), count, value);
}

void Shader::SetMatrix2(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2fv(id, count, transpose, value);
}
void Shader::SetMatrix2(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}
void Shader::SetMatrix3(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3fv(id, count, transpose, value);
}
void Shader::SetMatrix3(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}
void Shader::SetMatrix4(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4fv(id, count, transpose, value);
}
void Shader::SetMatrix4(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}

void Shader::SetMatrix2x3(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2x3fv(id, count, transpose, value);
}
void Shader::SetMatrix2x3(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2x3fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}
void Shader::SetMatrix3x2(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3x2fv(id, count, transpose, value);
}
void Shader::SetMatrix3x2(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3x2fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}

void Shader::SetMatrix2x4(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2x4fv(id, count, transpose, value);
}
void Shader::SetMatrix2x4(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix2x4fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}
void Shader::SetMatrix4x2(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4x2fv(id, count, transpose, value);
}
void Shader::SetMatrix4x2(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4x2fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}

void Shader::SetMatrix3x4(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3x4fv(id, count, transpose, value);
}
void Shader::SetMatrix3x4(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix3x4fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}
void Shader::SetMatrix4x3(const int id, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4x3fv(id, count, transpose, value);
}
void Shader::SetMatrix4x3(const std::string& name, int count, bool transpose, const float* value)
{
	glUseProgram(m_id);
	glUniformMatrix4x3fv(glGetUniformLocation(m_id, name.c_str()), count, transpose, value);
}

const unsigned int Shader::GetId() const
{
	return m_id;
}
