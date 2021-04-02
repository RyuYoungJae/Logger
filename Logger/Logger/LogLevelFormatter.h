#pragma once
#include "DefineEnum.h"

class LogLevelFormatter
{
public:
	static std::string Format(const LogLevel& level)
	{
		switch (level)
		{
		case LogLevel::Info: return "[I]";
		case LogLevel::Error: return "[E]";
		}

		return "NOTMATCHED";
	}
};

