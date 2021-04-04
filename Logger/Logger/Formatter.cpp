#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "Formatter.h"

void Formatter::AppendTime(std::string& target, const SYSTEMTIME& logTime)
{
	target.append(TimeFormatter::Format(logTime));
}

void Formatter::AppendLogLevel(std::string& target, const LogLevel& level)
{
	target.append(LogLevelFormatter::Format(level));
}
