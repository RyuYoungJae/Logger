#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "ILogChannel.h"
#include "LogCombiner.h"
//#include "IFormatter.h"
#include "DefineEnum.h"

class IFormatter;
class Logger
{
private:
	std::unique_ptr<LogCombiner> m_combiner;
	std::vector< std::unique_ptr<ILogChannel>> m_channel;

public:
	Logger();
	virtual ~Logger() = default;

	void RegisterChannel(std::unique_ptr<ILogChannel> channel);
	void RegisterFormatter(std::unique_ptr<IFormatter> formatter);

public:
	template<typename T, typename ...Arg>
	std::string Log(const LDateTime& logTime, const LogLevel& level, const std::string& log, T value, Arg...args)
	{
		if (m_channel.empty()) throw std::runtime_error("not exist channel");
		auto fmt = m_combiner->Format(logTime, level, log, value, args...);
		
		for (const auto& channel : m_channel)
		{
			channel->Log(level, fmt);
		}
		
		return fmt;
	}

	template<typename T, typename ...Arg>
	std::string Info(const LDateTime& logTime, const std::string& log, T value, Arg...args)
	{
		return Log(logTime, LogLevel::Info, log, value, args...);
	}

	template<typename T, typename ...Arg>
	std::string Error(const LDateTime& logTime, const std::string& log, T value, Arg...args)
	{
		return Log(logTime, LogLevel::Error, log, value, args...);
	}
};