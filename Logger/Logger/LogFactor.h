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
		std::stringstream stream;
		stream << value;

		m_value = stream.str();
	}

	const std::string& GetFactor() { return m_value; };
};