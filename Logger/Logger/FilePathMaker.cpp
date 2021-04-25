#include "TimeUtil.h"
#include "LDateTime.h"
#include "LogFile.h"
#include <sstream>
#include <Windows.h>
#include "FilePathMaker.h"

std::string FilePathMaker::Make()
{
	std::string path = "../log/";
	AppendDateTimeDir(path);
	path.append("/");
	AppendFileName(path);

	return path;
}

void FilePathMaker::AppendDateTimeDir(std::string& path)
{
	auto curDate = TimeUtil::GetLocalDate();

	std::stringstream curYMD;
	curYMD << curDate.Year % 2000;

	if (curDate.Month < 10) curYMD << 0;
	curYMD << curDate.Month;

	if (curDate.Day < 10) curYMD << 0;
	curYMD << curDate.Day;
	
	path.append(curYMD.str());
}

void FilePathMaker::AppendFileName(std::string& path)
{
	char fullPath[MAX_PATH]{};
	::GetModuleFileNameA(nullptr, fullPath, MAX_PATH);

	char fileName[MAX_PATH]{};
	_splitpath_s(fullPath, nullptr, 0, nullptr, 0, fileName, MAX_PATH, nullptr, 0);

	path.append(fileName);
	path.append(".log");
}

std::string FilePathMaker::TransferPath(const std::string& curPath)
{
	auto dot = curPath.find_last_of(".");
	auto transferPath = curPath.substr(0, dot) + "-";

	AppendHHMMSS(transferPath);
	transferPath.append(".log");

	return transferPath;
}

void FilePathMaker::AppendHHMMSS(std::string& path)
{
	SYSTEMTIME curTime;
	GetLocalTime(&curTime);

	std::stringstream curHMSI;

	if (curTime.wHour < 10)
	{
		curHMSI << 0;
	}
	curHMSI << curTime.wHour;

	if (curTime.wMinute < 10)
	{
		curHMSI << 0;
	}
	curHMSI << curTime.wMinute;

	if (curTime.wSecond < 10)
	{
		curHMSI << 0;
	}
	curHMSI << curTime.wSecond;

	if (curTime.wMilliseconds < 100)
	{
		curHMSI << 0;
	}
	curHMSI << curTime.wMilliseconds;

	path.append(curHMSI.str());
}

bool FilePathMaker::ChangeDateDirectory(std::shared_ptr<LogFile>& file)
{
	const std::string path = file->GetFilePath();
	
	auto index = path.find_last_of("/");
	auto dateDir = path.substr(0, index); // ../log/YMD
	
	index = dateDir.find_last_of("/");
	auto newDir = dateDir.substr(0, index) + "/"; // ../log
	AppendDateTimeDir(newDir);

	if (dateDir == newDir) return false;

	AppendFileName(newDir);
	file->Close();
	file->ChangeFilePath(newDir);

	return true;
}