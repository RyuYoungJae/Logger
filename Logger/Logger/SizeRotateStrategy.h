#pragma once
#include "IRotateStrategy.h"

class SizeRotateStrategy : public IRotateStrategy
{
private:
	int m_maxSize;

public:
	SizeRotateStrategy() = delete;
	SizeRotateStrategy(int maxSize);
	virtual ~SizeRotateStrategy() = default;

	bool NeedToRotate(const RotateData& data) const override;
};