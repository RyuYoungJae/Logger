#include "TimeUtil.h"
#include "TimeStrategy.h"

TimeStrategy::TimeStrategy(std::vector<RotateHHMM>&& info)
	: m_hhmm{ std::move(info) }
{
}

bool TimeStrategy::NeedToRotate(const RotateData& data) const
{
	const auto& fileCreateDate = data.FileCreateDate;
	if (fileCreateDate.Day <= 0) return false;

	auto curDate = TimeUtil::GetLocalDate();

	for (const auto& rotateTime : m_hhmm)
	{
		if (rotateTime.Hour <= curDate.Hour
			&& rotateTime.Minute <= curDate.Minute
			&& fileCreateDate.Hour <= rotateTime.Hour
			&& fileCreateDate.Minute < rotateTime.Minute) return true;
	}

	return false;
}