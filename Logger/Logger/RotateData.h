#pragma once
#include "LDateTime.h"

struct RotateHHMM
{
	int Hour{ 0 };
	int Minute{ 0 };

	RotateHHMM(int rotateHour, int roateMin) : Hour{ rotateHour }, Minute{ roateMin }
	{}
};

struct RotateData
{
	LDateTime FileCreateDate{};
	int FileSize{ 0 };
};