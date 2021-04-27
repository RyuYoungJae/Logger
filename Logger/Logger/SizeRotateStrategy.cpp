#include "RotateData.h"
#include "SizeRotateStrategy.h"

SizeRotateStrategy::SizeRotateStrategy(int maxSize) : m_maxSize{ maxSize }
{}

bool SizeRotateStrategy::NeedToRotate(const RotateData& data) const
{
	return m_maxSize < data.FileSize;
}
