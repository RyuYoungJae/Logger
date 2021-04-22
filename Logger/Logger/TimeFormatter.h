#pragma once
#include <string>
#include <math.h>
#include "LDateTime.h"

class TimeFormatter
{
public:
	static std::string Format(const LDateTime& time)
	{
		return "[" + MatchForm(time.Year, 4)
			+ "-" + MatchForm(time.Month, 2)
			+ "-" + MatchForm(time.Day, 2)
			+ " " + MatchForm(time.Hour, 2)
			+ ":" + MatchForm(time.Minute, 2)
			+ ":" + MatchForm(time.Second, 2)
			+ "." + MatchForm(time.Milliseconds, 3) + "]";
	}

private:
	static std::string MatchForm(int value, int maxDigitNum)
	{
		auto digit = 1;
		if(value > 0) digit = static_cast<int>(floor(log10(value) + 1));

		auto addZeroCnt = maxDigitNum - digit;

		std::string result{};
		while (addZeroCnt-- > 0)
		{
			result += std::to_string(0);
		}
		
		result += std::to_string(value);
		return result;
	}
};

