#include <Windows.h>
#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "Logger.h"

void Logger::AppendTime(std::string& target, const SYSTEMTIME& logTime)
{
	target.append(TimeFormatter::Format(logTime));
}

void Logger::AppendLogLevel(std::string& target, const LogLevel& level)
{
	target.append(LogLevelFormatter::Format(level));
}
