#pragma once
#include <string>

class LogFactor
{
private:
	std::string m_value;

public:
	LogFactor() = delete;
	
	template<typename T>
	LogFactor(const T& value)
	{
		m_value = std::to_string(value);
	}

	const std::string& GetFactor() { return m_value; };
};