#include "LDateTime.h"
#include "TimeUtil.h"
#include <chrono>

LDateTime TimeUtil::GetLocalDate()
{
	auto now = std::chrono::system_clock::now();
	auto timt = std::chrono::system_clock::to_time_t(now);
	std::tm tm{};
	localtime_s(&tm, &timt);

	LDateTime result{};
	result.Year = tm.tm_year + 1900;
	result.Month = tm.tm_mon + 1;
	result.DayOfWeek = tm.tm_wday;
	result.Day = tm.tm_mday;
	result.Hour = tm.tm_hour;
	result.Minute = tm.tm_min;
	result.Second = tm.tm_sec;
	result.Milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;

	return result;
}