#pragma once
#include <string>

class ILogChannel
{
public:
	ILogChannel() = default;
	virtual ~ILogChannel() = default;

	virtual void Write(const LogLevel& level, const std::string& fmt) = 0;
};