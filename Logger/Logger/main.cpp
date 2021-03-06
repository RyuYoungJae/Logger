#include <iostream>
#include "Logger.h"
#include "ConsoleChannel.h"
#include "TimeUtil.h"
#include "LDateTime.h"
#include "TimeFormatter.h"
#include "LogLevelFormatter.h"
#include "LogContentFormatter.h"
#include "FileChannel.h"
#include "FilePathMaker.h"
#include "SizeRotateStrategy.h"
#include "TimeRotateStrategy.h"
#include "RotateData.h"
#include "LogArchive.h"

int main()
{
	auto logger = std::make_unique<Logger>();
	logger->RegisterFormatter(std::make_unique<TimeFormatter>());
	logger->RegisterFormatter(std::make_unique<LogLevelFormatter>());
	logger->RegisterFormatter(std::make_unique<LogContentFormatter>());
	logger->RegisterChannel(std::make_unique<ConsoleChannel>());

	auto archive = std::make_unique<LogArchive>(FilePathMaker::Make());
	archive->RegisterRotateStrategy(std::make_unique<SizeRotateStrategy>(10000));

	std::vector<RotateHHMM> timeRotate;
	timeRotate.emplace_back(18, 15);
	archive->RegisterRotateStrategy(std::make_unique<TimeRotateStrategy>(std::move(timeRotate)));

	auto fileLogger = std::make_unique<FileChannel>();
	fileLogger->RegisterArchive(std::move(archive));

	logger->RegisterChannel(std::move(fileLogger));
	
	try
	{
		auto time = TimeUtil::GetLocalDate();

		int count = 10;
		while (count-- > 0)
		{
			logger->Error(time, "test % [%][%][%] code", count, 1.1, "3", "end");
			//logger->Info(time, "테스트 % [%][%][%] 코드", count, 1.1, "3", "end");
		}
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception : " << e.what();
	}

	return 0;
}