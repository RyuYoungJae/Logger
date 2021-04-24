#pragma once
#include <string>
#include <windows.h>

class LogFile
{
private:
	HANDLE m_file;
	std::string m_path;

public:
	LogFile() = delete;
	LogFile(const std::string& path);
	virtual ~LogFile();

public:
	void Write(const std::string& fmt);
	int GetSize();

private:
	void CreateLogFile();
	void CreateDirectories();
	bool IsExistDirectories();
};