#pragma once
#include "IRotateStrategy.h"

class FileSizeStrategy : public IRotateStrategy
{
private:
	int m_maxSize;

public:
	FileSizeStrategy() = delete;
	FileSizeStrategy(int maxSize);
	virtual ~FileSizeStrategy() = default;

	bool NeedToRotate(const RotateData& data) const override;

private:
	void FileOpen();
	bool NeedToRotate();
	void Rotate();
};