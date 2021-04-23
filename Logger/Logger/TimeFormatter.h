#pragma once
#include "IFormatter.h"

class TimeFormatter : public IFormatter
{
public:
	std::string Format(const LogFormatData& data) override;

private:
	std::string MatchForm(int value, int maxDigitNum);
};

