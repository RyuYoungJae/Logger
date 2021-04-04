#pragma once
#include "ILogChannel.h"
#include <windows.h>

enum class LogLevel;
class ConsoleChannel : public ILogChannel
{
private:
	HANDLE m_handle;

public:
	ConsoleChannel();
	virtual ~ConsoleChannel();

public:
	void Log(const LogLevel& level, const std::string& fmt) override;

private:
	void ChangeColor(const LogLevel& level);
};

