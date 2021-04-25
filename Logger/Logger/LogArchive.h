#pragma once

class LogFile;
class LogArchive
{
public:
	LogArchive() = default;
	virtual ~LogArchive() = default;

public:
	void Rotate(std::shared_ptr<LogFile>& curFile);
	void Transfer(const std::shared_ptr<LogFile>& file);
};