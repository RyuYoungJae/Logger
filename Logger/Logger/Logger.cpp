#include "ILogChannel.h"
#include "IFormatter.h"
#include "Logger.h"

Logger::Logger() : m_combiner{std::make_unique<LogCombiner>()}
{}

void Logger::RegisterChannel(std::unique_ptr<ILogChannel> channel)
{
	m_channel.emplace_back(std::move(channel));
}

void Logger::RegisterFormatter(std::unique_ptr<IFormatter> formatter)
{
	m_combiner->Register(std::move(formatter));
}