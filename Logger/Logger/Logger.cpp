#include <iostream>
#include "Logger.h"

const std::string& Logger::Error(const std::string& log)
{
	std::cout << log << std::endl;
	return log;
}