#include "Formatter.h"
#include "ILogChannel.h"
#include "Logger.h"

Logger::Logger() : m_formatter{std::make_unique<Formatter>()}
{}


