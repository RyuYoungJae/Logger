#include <iostream>
#include "Logger.h"
#include "ConsoleChannel.h"
#include "TimeUtil.h"
#include "LDateTime.h"

int main()
{
	auto logger = std::make_unique<Logger>();
	logger->RegisterChannel(std::make_unique<ConsoleChannel>());
	try
	{
		auto time = TimeUtil::GetLocalDate();

		logger->Error(time, "test % [%][%][%] code", 1, 1.1, "3", "end");
		logger->Info(time, "테스트 % [%][%][%] 코드", 1, 1.1, "3", "end");
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception : " << e.what();
	}

	return 0;
}