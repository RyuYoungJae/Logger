#pragma once
#include <string>
#include "FactorParsing.h"

class Logger
{
public:
	Logger() = default;
	virtual ~Logger() = default;

public:
	template<typename T, typename ...Arg>
	std::string Write(const SYSTEMTIME& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		std::string result{};
		AppendTime(result, logTime);
		AppendLogLevel(result, level);
		AppendParsingResult(result, log, value, args...);

		return result;
	}

private:
	void AppendTime(std::string& target, const SYSTEMTIME& logTime);
	void AppendLogLevel(std::string& target, const LogLevel& level);

private:
	template<typename T, typename ...Arg>
	void AppendParsingResult(std::string& result, const std::string& log, T value, Arg...arg)
	{
		FactorParsing parsing{};
		auto parsingResult = parsing.Parsing(log, value, arg...);
		result.append(parsingResult);
	}
};