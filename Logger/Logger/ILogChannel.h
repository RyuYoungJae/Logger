#pragma once
#include <string>

class ILogChannel
{
public:
	virtual void Write(const LogLevel& level, const std::string& fmt) = 0;
};