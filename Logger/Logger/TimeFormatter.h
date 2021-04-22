#pragma once
#include <string>
#include "LDateTime.h"

class TimeFormatter
{
public:
	static std::string Format(const LDateTime& time)
	{
		return "[" + std::to_string(time.Year)
			+ "-" + std::to_string(time.Month)
			+ "-" + std::to_string(time.Day)
			+ " " + std::to_string(time.Hour)
			+ ":" + std::to_string(time.Minute)
			+ ":" + std::to_string(time.Second)
			+ "." + std::to_string(time.Milliseconds) + "]";
	}
};

