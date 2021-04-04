#include "Formatter.h"
#include "ILogChannel.h"
#include "Logger.h"

Logger::Logger() : m_formatter{std::make_unique<Formatter>()}
{}

void Logger::RegisterChannel(std::unique_ptr<ILogChannel> channel)
{
	m_channel.emplace_back(std::move(channel));
}

