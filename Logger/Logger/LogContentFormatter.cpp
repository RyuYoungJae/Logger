#include "LogFormatData.h"
#include "LogContentFormatter.h"

std::string LogContentFormatter::Format(const LogFormatData& data)
{
	std::string result{ data.Content.str };

	for (const auto& factor : data.Content.factors)
	{
		auto idx = result.find('%');
		if (idx == std::string::npos) break;

		result.replace(idx, 1, factor.GetFactor());
	}

	return result;
}