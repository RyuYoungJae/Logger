#pragma once
#include <vector>

class LogFile;
class IRotateStrategy;
class LogArchive
{
private:
	std::string m_path;
	std::shared_ptr<LogFile> m_file;
	std::vector<std::unique_ptr<IRotateStrategy>> m_roateStrategy;

public:
	LogArchive() = delete;
	LogArchive(const std::string& path);
	virtual ~LogArchive() = default;
	void RegisterRotateStrategy(std::unique_ptr<IRotateStrategy> strategy);

public:
	std::shared_ptr<LogFile> Request();
	void Rotate(std::shared_ptr<LogFile>& curFile);
	void Transfer(const std::shared_ptr<LogFile>& file);

private:
	void FileOpen();
	bool NeedToRotate();
	void Rotate();
};