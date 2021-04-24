#include "RotateData.h"
#include "FileSizeStrategy.h"

FileSizeStrategy::FileSizeStrategy(int maxSize) : m_maxSize{ maxSize }
{}

bool FileSizeStrategy::NeedToRotate(const RotateData& data) const
{
	return m_maxSize < data.FileSize;
}
