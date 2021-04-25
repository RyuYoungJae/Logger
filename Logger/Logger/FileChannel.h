#pragma once
#include "ILogChannel.h"
#include <vector>

class LogFile;
class IRotateStrategy;
class LogArchive;
class FileChannel : public ILogChannel
{
private:
	std::shared_ptr<LogFile> m_file;
	std::string m_path;
	std::vector<std::unique_ptr<IRotateStrategy>> m_roateStrategy;
	std::unique_ptr<LogArchive> m_archive;

public:
	FileChannel() = delete;
	FileChannel(const std::string& path);
	virtual ~FileChannel() = default;
	void RegisterRotateStrategy(std::unique_ptr<IRotateStrategy> strategy);

	void Log(const LogLevel& level, const std::string& fmt) override;

private:
	void FileOpen();
	bool NeedToRotate();
	void Rotate();
};