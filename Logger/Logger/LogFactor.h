#pragma once
#include <string>
#include <sstream>

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

	virtual ~LogFactor() = default;

	const std::string& GetFactor() { return m_value; };
};