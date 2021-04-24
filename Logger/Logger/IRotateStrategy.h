#pragma once

struct RotateData;
class IRotateStrategy
{
public:
	virtual bool NeedToRotate(const RotateData& data) const = 0;
};