#pragma once
#include "IRotateStrategy.h"
#include "RotateData.h"
#include <vector>

class TimeStrategy : public IRotateStrategy
{
private:
	std::vector<RotateHHMM> m_hhmm;

public:
	TimeStrategy() = delete;
	TimeStrategy(std::vector<RotateHHMM>&& info);
	virtual ~TimeStrategy() = default;

	bool NeedToRotate(const RotateData& data) const override;
};