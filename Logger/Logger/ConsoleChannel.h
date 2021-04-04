#pragma once
#include "ILogChannel.h"

enum class LogLevel;
class ConsoleChannel : public ILogChannel
{
public:
	ConsoleChannel() = default;
	virtual ~ConsoleChannel() = default;

public:
	void Write(const LogLevel& level, const std::string& fmt) override;
};

