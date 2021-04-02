#pragma once
#include <string>

class Logger
{
public:
	Logger() = default;
	virtual ~Logger() = default;

public:
	std::string Write(const SYSTEMTIME& logTime, const LogLevel& level, const std::string& log);
};