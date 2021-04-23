#include <string>
#include <math.h>
#include "LogFormatData.h"
#include "TimeFormatter.h"

std::string TimeFormatter::Format(const LogFormatData& data)
{
	auto time = data.Time;
	return "[" + MatchForm(time.Year, 4)
		+ "-" + MatchForm(time.Month, 2)
		+ "-" + MatchForm(time.Day, 2)
		+ " " + MatchForm(time.Hour, 2)
		+ ":" + MatchForm(time.Minute, 2)
		+ ":" + MatchForm(time.Second, 2)
		+ "." + MatchForm(time.Milliseconds, 3) + "]";
}

std::string TimeFormatter::MatchForm(int value, int maxDigitNum)
{
	auto digit = 1;
	if (value > 0) digit = static_cast<int>(floor(log10(value) + 1));

	auto addZeroCnt = maxDigitNum - digit;

	std::string result{};
	while (addZeroCnt-- > 0)
	{
		result += std::to_string(0);
	}

	result += std::to_string(value);
	return result;
}