#include "DefineEnum.h"
#include "ConsoleChannel.h"
#include <iostream>

ConsoleChannel::ConsoleChannel() : m_handle{ INVALID_HANDLE_VALUE }
{
	m_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

ConsoleChannel::~ConsoleChannel()
{
	m_handle = INVALID_HANDLE_VALUE;
}

void ConsoleChannel::Log(const LogLevel& level, const std::string& fmt)
{
	if (m_handle == INVALID_HANDLE_VALUE) return;

	ChangeColor(level);

	DWORD written = 0;
	WriteConsoleA(m_handle, fmt.c_str(), fmt.length(), &written, nullptr);
}

void ConsoleChannel::ChangeColor(const LogLevel& level)
{
	auto color = 0;
	switch (level)
	{
	case LogLevel::Error:
	{
		//RED
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;
		break;
	}
	default:
	{
		//WHITE
		color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		break;
	}
	}

	SetConsoleTextAttribute(m_handle, color);
}