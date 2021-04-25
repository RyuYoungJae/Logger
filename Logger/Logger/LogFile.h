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
	void CreateDirectories();
	void Write(const std::string& fmt);
	int GetSize();
	bool IsExist();
	void Close();
	const std::string& GetFilePath();
	void ChangeFilePath(const std::string& path);

private:
	void CreateLogFile();
	bool IsExistDirectories();
};