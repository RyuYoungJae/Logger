#pragma once
#include "LDateTime.h"
#include "LogFormatData.h"
#include "LogFactorConverter.h"

enum class LogLevel;
class IFormatter;
class LogCombiner
{
private:
	std::vector< std::unique_ptr<IFormatter>> m_formatter;
	
public:
	LogCombiner() = default;
	virtual ~LogCombiner() = default;

	void Register(std::unique_ptr<IFormatter> formatter);

public:
	template<typename T, typename ...Arg>
	std::string Format(const LDateTime& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		auto factors = LogFactorConverter::Convert(value, args...);
		auto formatData = LogFormatData::Make(logTime, level, log, std::move(factors));

		auto result = Append(formatData);
		result.append("\n");

		return result;
	}

private:
	std::string Append(const LogFormatData& data);
};

