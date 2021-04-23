#pragma once
#include "LogFactor.h"
#include <vector>

class LogFactorConverter
{
public:
	template<typename T, typename ...Arg>
	static std::vector<LogFactor> Convert(T value, Arg...args)
	{
		std::vector<LogFactor> result;
		result.emplace_back(value);
		return Convert(result, args...);
	}

	template<typename T, typename ...Arg>
	static std::vector<LogFactor> Convert(std::vector<LogFactor>& result, T value, Arg...args)
	{
		result.emplace_back(value);
		return Convert(result, args...);
	}

	template<typename T>
	static std::vector<LogFactor> Convert(std::vector<LogFactor>& result, T value)
	{
		result.emplace_back(value);
		return result;
	}
};