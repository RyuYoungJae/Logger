#pragma once
#include "IRotateStrategy.h"
#include "RotateData.h"
#include <vector>

class TimeRotateStrategy : public IRotateStrategy
{
private:
	std::vector<RotateHHMM> m_hhmm;

public:
	TimeRotateStrategy() = delete;
	TimeRotateStrategy(std::vector<RotateHHMM>&& info);
	virtual ~TimeRotateStrategy() = default;

	bool NeedToRotate(const RotateData& data) const override;
};