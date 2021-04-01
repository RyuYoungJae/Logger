#include "pch.h"
#include <memory>
#include <time.h>
#include <Windows.h>
#include "../Logger/DefineEnum.h"
#include "../Logger/TimeFormatter.h"
#include "../Logger/LogLevelFormatter.h"

TEST(TimeFormatter, Format_ConvertString_Equal)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	auto formatter = std::make_unique<TimeFormatter>();
	auto result = formatter->Format(time);
	
	auto expect = "[" + std::to_string(time.wYear)
					+ "-" + std::to_string(time.wMonth)
					+ "-" + std::to_string(time.wDay)
					+ " " + std::to_string(time.wHour)
					+ ":" + std::to_string(time.wMinute)
					+ ":" + std::to_string(time.wSecond)
					+ "." + std::to_string(time.wMilliseconds) + "]";

	EXPECT_EQ(result, expect);
}

TEST(LogLevelFormatter, Format_ConvertLevelMark_Equal)
{
	auto formatter = std::make_unique<LogLevelFormatter>();
	auto InfoMark = formatter->Format(LogLevel::Info);
	auto ErrorMark = formatter->Format(LogLevel::Error);

	EXPECT_TRUE(InfoMark == "[I]" && ErrorMark == "[E]");
}
