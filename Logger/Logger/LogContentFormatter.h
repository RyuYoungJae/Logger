#pragma once
#include "IFormatter.h"

class LogContentFormatter : public IFormatter
{
public:
	std::string Format(const LogFormatData& data) override;
};