#include "pch.h"
#include <memory>
#include <time.h>
#include <regex>
#include "../Logger/TimeUtil.cpp"
#include "../Logger/LDateTime.h"
#include "../Logger/DefineEnum.h"
#include "../Logger/TimeFormatter.h"
#include "../Logger/LogLevelFormatter.h"
#include "../Logger/Formatter.cpp"
#include "../Logger/FactorParsing.h"
#include "../Logger/Logger.cpp"
#include "../Logger/ConsoleChannel.cpp"

/********************************************
TODO:
1. 로그 레벨은 INFO, ERROR가 존재, [I],[E]로 표기
2. INFO는 하얀색, Error는 빨간색으로 윈도우 콘솔에 나타나야한다.
3. 로그 양식은 [로그 남은 날짜][로그 레벨][내용]
4. % 값을 기준으로 인자를 대입 하여야한다.
*********************************************/

TEST(TimeFormatter, Format_ConvertString_Equal)
{
	LDateTime time{};
	time.Year = 2021;
	time.Month = 4;
	time.Day = 22;
	time.Hour = 19;
	time.Minute = 22;
	time.Second = 0;

	auto result = TimeFormatter::Format(time);	
	auto expect = "[2021-04-22 19:22:00.000]";

	EXPECT_EQ(result, expect);
}

TEST(LogLevelFormatter, Format_ConvertLevelMark_Equal)
{
	auto InfoMark = LogLevelFormatter::Format(LogLevel::Info);
	auto ErrorMark = LogLevelFormatter::Format(LogLevel::Error);

	EXPECT_TRUE(InfoMark == "[I]" && ErrorMark == "[E]");
}

TEST(FactorParsing, Parsing_RightPosition_Equal)
{
	auto parsing = std::make_unique<FactorParsing>();
	const auto result = parsing->Parsing("test code : [%,%]", 3, "kkk");

	EXPECT_EQ(result, "test code : [3,kkk]");
}

TEST(Formatter, Format_Call_Equal)
{
	auto formatter = std::make_unique<Formatter>();

	LDateTime time{};
	time.Year = 2021;
	time.Month = 4;
	time.Day = 22;
	time.Hour = 19;
	time.Minute = 22;
	time.Second = 0;

	const auto result = formatter->Format(time, LogLevel::Error, "test% code [%][%]", 1, "kk", "end");

	std::string expect = "[2021-04-22 19:22:00.000]";
	expect.append(LogLevelFormatter::Format(LogLevel::Error));
	expect.append("test1 code [kk][end]\n");

	EXPECT_EQ(result, expect);
}