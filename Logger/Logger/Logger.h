#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include "DefineEnum.h"
#include "Formatter.h"

class ILogChannel;
class Logger
{
private:
	std::unique_ptr<Formatter> m_formatter;
	std::vector< std::unique_ptr<ILogChannel>> m_channel;

public:
	Logger();
	virtual ~Logger() = default;

public:
	template<typename T, typename ...Arg>
	std::string Write(const SYSTEMTIME& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		/*auto fmt = m_formatter->Format(logTime, level, log, value, args...);
		m_channel->Write(level, fmt);

		return fmt;*/
	}

	template<typename T, typename ...Arg>
	std::string Info(const SYSTEMTIME& logTime, const std::string& log, T value, Arg...args)
	{
		return Write(logTime, LogLevel::Info, log, value, args...);
	}

	template<typename T, typename ...Arg>
	std::string Error(const SYSTEMTIME& logTime, const std::string& log, T value, Arg...args)
	{
		return Write(logTime, LogLevel::Error, log, value, args...);
	}
};