#include <Windows.h>
#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "Logger.h"

std::string Logger::Write(const SYSTEMTIME& logTime, const LogLevel& level, const std::string& log)
{
	std::string result{};

	result.append(TimeFormatter::Format(logTime));
	result.append(LogLevelFormatter::Format(level));
	result.append(log);

	return result;
}