#pragma once
#include "IFormatter.h"

struct LogFormatData;
class LogLevelFormatter : public IFormatter
{
public:
	std::string Format(const LogFormatData& data) override;
};