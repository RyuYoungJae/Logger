#pragma once

class TimeFormatter
{
public:
	std::string Format(const SYSTEMTIME& time)
	{
		return "[" + std::to_string(time.wYear)
			+ "-" + std::to_string(time.wMonth)
			+ "-" + std::to_string(time.wDay)
			+ " " + std::to_string(time.wHour)
			+ ":" + std::to_string(time.wMinute)
			+ ":" + std::to_string(time.wSecond)
			+ "." + std::to_string(time.wMilliseconds) + "]";
	}
};

