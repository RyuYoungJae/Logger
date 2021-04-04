#pragma once
#include <string>
#include <vector>
#include "LogFactor.h"

class FactorParsing
{
private:
	std::vector<std::unique_ptr<LogFactor>> m_factors;

public:
	FactorParsing() = default;
	virtual ~FactorParsing() = default;

public:
	template<typename T, typename ...Arg>
	std::string Parsing(const std::string& str, T value, Arg...args)
	{
		m_factors.emplace_back(std::make_unique<LogFactor>(value));
		return Parsing(str, args...);
	}

	template<typename T, typename ...Arg>
	std::string Parsing(const std::string& str, T value)
	{
		m_factors.emplace_back(std::make_unique<LogFactor>(value));

		return Parsing(str);
	}

	std::string Parsing(const std::string& str)
	{
		std::string result{ str };
		
		for (const auto& factor : m_factors)
		{
			auto idx = result.find('%');
			if (idx == std::string::npos) break;

			result.replace(idx, 1, factor->GetFactor());
		}

		return result;
	}
};

