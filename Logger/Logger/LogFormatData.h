#pragma once
#include "LDateTime.h"
#include "DefineEnum.h"
#include "LogFactor.h"
#include <vector>

struct LogContent
{
	std::string str{};
	std::vector<LogFactor> factors{};
};

struct LogFormatData
{
	LDateTime Time{};
	LogLevel Level{};
	LogContent Content{};

	static LogFormatData Make(const LDateTime& time, const LogLevel& level, const std::string& fullStr, std::vector<LogFactor>&& factors)
	{
		LogFormatData data;
		data.Time = time;
		data.Level = level;
		data.Content.str = fullStr;
		data.Content.factors = std::move(factors);

		return data;
	}
};
