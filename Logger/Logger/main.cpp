#include <iostream>
#include "Logger.h"
#include "ConsoleChannel.h"
#include "TimeUtil.h"
#include "LDateTime.h"
#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "LogContentFormatter.h"
#include "FileChannel.h"

int main()
{
	auto logger = std::make_unique<Logger>();
	logger->RegisterFormatter(std::make_unique<TimeFormatter>());
	logger->RegisterFormatter(std::make_unique<LogLevelFormatter>());
	logger->RegisterFormatter(std::make_unique<LogContentFormatter>());
	logger->RegisterChannel(std::make_unique<ConsoleChannel>());
	logger->RegisterChannel(std::make_unique<FileChannel>("../log/test.log"));
	try
	{
		auto time = TimeUtil::GetLocalDate();

		logger->Error(time, "test % [%][%][%] code", 0, 1.1, "3", "end");
		logger->Info(time, "테스트 % [%][%][%] 코드", 0, 1.1, "3", "end");
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception : " << e.what();
	}

	return 0;
}