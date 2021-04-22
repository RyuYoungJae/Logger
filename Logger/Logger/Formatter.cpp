#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "LDateTime.h"
#include "Formatter.h"

void Formatter::AppendTime(std::string& target, const LDateTime& logTime)
{
	target.append(TimeFormatter::Format(logTime));
}

void Formatter::AppendLogLevel(std::string& target, const LogLevel& level)
{
	target.append(LogLevelFormatter::Format(level));
}
