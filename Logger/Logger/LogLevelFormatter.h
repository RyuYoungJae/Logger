#pragma once
#include "DefineEnum.h"

class LogLevelFormatter
{
public:
	std::string Format(const LogLevel& level)
	{
		switch (level)
		{
		case LogLevel::Info: return "[I]";
		case LogLevel::Error: return "[E]";
		}

		return "NOTMATCHED";
	}
};

