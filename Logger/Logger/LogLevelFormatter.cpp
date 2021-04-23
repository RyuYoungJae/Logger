#include "DefineEnum.h"
#include "LogFormatData.h"
#include "LogLevelFormatter.h"

std::string LogLevelFormatter::Format(const LogFormatData& data)
{
	switch (data.Level)
	{
	case LogLevel::Info: return "[I]";
	case LogLevel::Error: return "[E]";
	}

	return "NOTMATCHED";
}