#pragma once
#include "FactorParsing.h"
#include "LDateTime.h"

enum class LogLevel;
class Formatter
{
public:
	Formatter() = default;
	virtual ~Formatter() = default;

public:
	template<typename T, typename ...Arg>
	std::string Format(const LDateTime& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		std::string result{};
		AppendTime(result, logTime);
		AppendLogLevel(result, level);
		AppendParsingResult(result, log, value, args...);
		result.append("\n");

		return result;
	}

private:
	void AppendTime(std::string& target, const LDateTime& logTime);
	void AppendLogLevel(std::string& target, const LogLevel& level);

private:
	template<typename T, typename ...Arg>
	void AppendParsingResult(std::string& target, const std::string& log, T value, Arg...arg)
	{
		FactorParsing parsing{};
		auto parsingResult = parsing.Parsing(log, value, arg...);
		target.append(parsingResult);
	}
};

