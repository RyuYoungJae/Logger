#include "pch.h"
#include <memory>
#include <time.h>
#include <regex>
#include <Windows.h>
#include "../Logger/DefineEnum.h"
#include "../Logger/TimeFormatter.h"
#include "../Logger/LogLevelFormatter.h"
#include "../Logger/Logger.cpp"
#include "../Logger/FactorParsing.h"

TEST(TimeFormatter, Format_ConvertString_Equal)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	auto result = TimeFormatter::Format(time);
	
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
	auto InfoMark = LogLevelFormatter::Format(LogLevel::Info);
	auto ErrorMark = LogLevelFormatter::Format(LogLevel::Error);

	EXPECT_TRUE(InfoMark == "[I]" && ErrorMark == "[E]");
}

TEST(Logger, Write_WriteErrorLog_Equal)
{
	auto logger = std::make_unique<Logger>();

	SYSTEMTIME time;
	GetLocalTime(&time);
	const auto word = "test code";
	const auto result = logger->Write(time, LogLevel::Error, word);

	auto expect = "[" + std::to_string(time.wYear)
		+ "-" + std::to_string(time.wMonth)
		+ "-" + std::to_string(time.wDay)
		+ " " + std::to_string(time.wHour)
		+ ":" + std::to_string(time.wMinute)
		+ ":" + std::to_string(time.wSecond)
		+ "." + std::to_string(time.wMilliseconds) + "]";
	expect.append(LogLevelFormatter::Format(LogLevel::Error));
	expect.append(word);

	EXPECT_EQ(result, expect);
}

TEST(FactorParsing, Parsing_RightPosition_Equal)
{
	auto parsing = std::make_unique<FactorParsing>();
	const auto result = parsing->Parsing("test cod : [%,%]", 3, "kkk");

	EXPECT_EQ(result, "test cod : [3,kkk]");
}