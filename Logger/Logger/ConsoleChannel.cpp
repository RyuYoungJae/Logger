#include "DefineEnum.h"
#include "ConsoleChannel.h"
#include <iostream>

void ConsoleChannel::Write(const LogLevel& level, const std::string& fmt)
{
	std::cout << fmt;
}
