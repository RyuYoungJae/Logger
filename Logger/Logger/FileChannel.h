#pragma once
#include "ILogChannel.h"
#include <vector>

class LogFile;
class IRotateStrategy;
class FileChannel : public ILogChannel
{
private:
	std::shared_ptr<LogFile> m_file;
	std::string m_path;
	std::vector<IRotateStrategy> m_roateStrategy;

public:
	FileChannel() = delete;
	FileChannel(const std::string& path);
	virtual ~FileChannel() = default;

	void Log(const LogLevel& level, const std::string& fmt) override;

private:
	void FileOpen();
	bool NeedToRotate();
	void Rotate();
};