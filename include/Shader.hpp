#pragma once

#include <string>

class Shader
{
	public:
	Shader(const std::string vertexPath, const std::string fragmentPath);
	~Shader();

	void Use() const;

	void SetBool(const std::string& name, bool value) const;

	void SetFloat(const std::string& name, float value) const;
	void Set2Float(const std::string& name, float value1, float value2) const;
	void Set3Float(const std::string& name, float value1, float value2, float value3) const;
	void Set4Float(const std::string& name, float value1, float value2, float value3, float value4) const;

	void SetInt(const std::string& name, int value) const;
	void Set2Int(const std::string& name, int value1, int value2) const;
	void Set3Int(const std::string& name, int value1, int value2, int value3) const;
	void Set4Int(const std::string& name, int value1, int value2, int value3, int value4) const;

	void SetUInt(const std::string& name, unsigned int value) const;
	void Set2UInt(const std::string& name, unsigned int value1, unsigned int value2) const;
	void Set3UInt(const std::string& name, unsigned int value1, unsigned int value2, unsigned int value3) const;
	void Set4UInt(const std::string& name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4) const;
	
	void SetFloatArray(const std::string& name,  int count, const float* value) const;
	void Set2FloatArray(const std::string& name, int count, const float* value) const;
	void Set3FloatArray(const std::string& name, int count, const float* value) const;
	void Set4FloatArray(const std::string& name, int count, const float* value) const;

	void SetIntArray(const std::string& name, int count, const int* value) const;
	void Set2IntArray(const std::string& name, int count, const int* value) const;
	void Set3IntArray(const std::string& name, int count, const int* value) const;
	void Set4IntArray(const std::string& name, int count, const int* value) const;

	void SetUIntArray(const std::string& name, int count, const unsigned int* value) const;
	void Set2UIntArray(const std::string& name, int count, const unsigned int* value) const;
	void Set3UIntArray(const std::string& name, int count, const unsigned int* value) const;
	void Set4UIntArray(const std::string& name, int count, const unsigned int* value) const;

	void SetMatrix2(const std::string& name, int count, bool transpose, const float* value);
	void SetMatrix3(const std::string& name, int count, bool transpose, const float* value);
	void SetMatrix4(const std::string& name, int count, bool transpose, const float* value);

	void SetMatrix2x3(const std::string& name, int count, bool transpose, const float* value);
	void SetMatrix3x2(const std::string& name, int count, bool transpose, const float* value);

	void SetMatrix2x4(const std::string& name, int count, bool transpose, const float* value);
	void SetMatrix4x2(const std::string& name, int count, bool transpose, const float* value);

	void SetMatrix3x4(const std::string& name, int count, bool transpose, const float* value);
	void SetMatrix4x3(const std::string& name, int count, bool transpose, const float* value);

	const unsigned int GetId() const;

	private:
	unsigned int m_id;
};