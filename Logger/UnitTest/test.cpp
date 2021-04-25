#include "pch.h"
#include <memory>
#include <time.h>
#include <regex>
#include "../Logger/TimeUtil.cpp"
#include "../Logger/DefineEnum.h"
#include "../Logger/TimeFormatter.cpp"
#include "../Logger/LogLevelFormatter.cpp"
#include "../Logger/LogCombiner.cpp"
#include "../Logger/LogFormatData.h"
#include "../Logger/LogContentFormatter.cpp"
#include "../Logger/LogFile.cpp"
#include "../Logger/LogArchive.cpp"

/********************************************
TODO:
1. 로그 레벨은 INFO, ERROR가 존재, [I],[E]로 표기
2. INFO는 하얀색, Error는 빨간색으로 윈도우 콘솔에 나타나야한다.
3. 로그 양식은 [로그 남은 날짜][로그 레벨][내용]
4. % 값을 기준으로 인자를 대입 하여야한다.
*********************************************/

TEST(TimeFormatter, Format_ConvertLogFormat_Equal)
{
	LogFormatData data{};
	data.Time.Year = 2021;
	data.Time.Month = 4;
	data.Time.Day = 22;
	data.Time.Hour = 19;
	data.Time.Minute = 22;
	data.Time.Second = 0;

	auto formatter = std::make_unique<TimeFormatter>();
	auto result = formatter->Format(data);
	auto expect = "[2021-04-22 19:22:00.000]";

	EXPECT_EQ(result, expect);
}

TEST(LogLevelFormatter, Format_ConvertLogFormat_Equal)
{
	LogFormatData infoData{};
	infoData.Level = LogLevel::Info;
	auto infoFormatter = std::make_unique<LogLevelFormatter>();
	auto InfoMark = infoFormatter->Format(infoData);

	LogFormatData errorData{};
	errorData.Level = LogLevel::Error;
	auto errorFormatter = std::make_unique<LogLevelFormatter>();
	auto ErrorMark = errorFormatter->Format(errorData);
	
	EXPECT_TRUE(InfoMark == "[I]" && ErrorMark == "[E]");
}

TEST(LogContentFormatter, Format_ConvertLogFormat_Equal)
{
	LogFormatData data{};
	data.Content.str = "test code : [%,%]";
	data.Content.factors.emplace_back(3);
	data.Content.factors.emplace_back("kkk");

	auto formatter = std::make_unique<LogContentFormatter>();
	auto result = formatter->Format(data);

	EXPECT_EQ(result, "test code : [3,kkk]");
}

TEST(LogCombiner, Format_ConvertLogFormat_Equal)
{
	LDateTime time{};
	time.Year = 2021;
	time.Month = 4;
	time.Day = 22;
	time.Hour = 19;
	time.Minute = 22;
	time.Second = 0;
	
	auto combiner = std::make_unique<LogCombiner>();
	combiner->Register(std::make_unique<TimeFormatter>());
	combiner->Register(std::make_unique<LogLevelFormatter>());
	combiner->Register(std::make_unique<LogContentFormatter>());

	const auto result = combiner->Format(time, LogLevel::Error, "test% code [%][%]", 1, "kk", "end");

	std::string expect = "[2021-04-22 19:22:00.000][E]test1 code [kk][end]\n";

	EXPECT_EQ(result, expect);
}