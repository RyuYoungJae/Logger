#include "LogLevelFormatter.h"
#include "IFormatter.h"
#include "LogCombiner.h"

void LogCombiner::Register(std::unique_ptr<IFormatter> formatter)
{
	m_formatter.push_back(std::move(formatter));
}

std::string LogCombiner::Append(const LogFormatData& data)
{
	if (m_formatter.empty()) throw std::runtime_error("not exist formatter");

	std::string result{};
	for (const auto& formatter : m_formatter)
	{
		result += formatter->Format(data);
	}

	return result;
}
