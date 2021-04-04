#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <stdexcept>
#include "Formatter.h"
#include "DefineEnum.h"
#include "ILogChannel.h"

class Logger
{
private:
	std::unique_ptr<Formatter> m_formatter;
	std::vector< std::unique_ptr<ILogChannel>> m_channel;

public:
	Logger();
	virtual ~Logger() = default;

	void RegisterChannel(std::unique_ptr<ILogChannel> channel);

public:
	template<typename T, typename ...Arg>
	std::string Log(const SYSTEMTIME& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		if (m_channel.empty()) throw std::runtime_error("not exist channel");
		auto fmt = m_formatter->Format(logTime, level, log, value, args...);
		
		for (const auto& channel : m_channel)
		{
			channel->Log(level, fmt);
		}
		
		return fmt;
	}

	template<typename T, typename ...Arg>
	std::string Info(const SYSTEMTIME& logTime, const std::string& log, T value, Arg...args)
	{
		return Log(logTime, LogLevel::Info, log, value, args...);
	}

	template<typename T, typename ...Arg>
	std::string Error(const SYSTEMTIME& logTime, const std::string& log, T value, Arg...args)
	{
		return Log(logTime, LogLevel::Error, log, value, args...);
	}
};