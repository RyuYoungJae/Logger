#pragma once
#include "ILogChannel.h"

class LogArchive;
class FileChannel : public ILogChannel
{
private:
	std::unique_ptr<LogArchive> m_archive;

public:
	FileChannel() = default;
	virtual ~FileChannel() = default;

	void RegisterArchive(std::unique_ptr<LogArchive> archive);

	void Log(const LogLevel& level, const std::string& fmt) override;
};