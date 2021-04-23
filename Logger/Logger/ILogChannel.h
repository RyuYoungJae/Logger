#pragma once
#include <string>

enum class LogLevel;
class ILogChannel
{
public:
	ILogChannel() = default;
	virtual ~ILogChannel() = default;

	virtual void Log(const LogLevel& level, const std::string& fmt) = 0;
};