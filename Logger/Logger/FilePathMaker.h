#pragma once
#include <string>

class LogFile;
class FilePathMaker
{
public:
	static std::string Make();
	static std::string TransferPath(const std::string& curPath);

	static bool ChangeDateDirectory(std::shared_ptr<LogFile>& file);

private:
	static void AppendDateTimeDir(std::string& path);
	static void AppendFileName(std::string& path);
	static void AppendHHMMSS(std::string& path);
};