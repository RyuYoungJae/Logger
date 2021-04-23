#pragma once
#include <string>

struct LogFormatData;
class IFormatter
{
public:
	virtual std::string Format(const LogFormatData& data) = 0;
};