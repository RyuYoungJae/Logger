#include "LogFile.h"
#include "FilePathMaker.h"
#include "RotateData.h"
#include "TimeUtil.h"
#include "IRotateStrategy.h"
#include <sstream>
#include "LogArchive.h"

LogArchive::LogArchive(const std::string& path) : m_path{ path }, m_file{ nullptr }
{
}

void LogArchive::RegisterRotateStrategy(std::unique_ptr<IRotateStrategy> strategy)
{
	m_roateStrategy.push_back(std::move(strategy));
}

std::shared_ptr<LogFile> LogArchive::Request()
{
	FileOpen();
	if (NeedToRotate()) Rotate(m_file);

	return m_file;
}

void LogArchive::FileOpen()
{
	if (m_file == nullptr)
	{
		m_file = std::make_shared<LogFile>(m_path);

		if (m_file->IsExist()) Transfer(m_file);

		m_file->CreateDirectories();
	}
}

bool LogArchive::NeedToRotate()
{
	RotateData data;
	data.Time = TimeUtil::GetLocalDate();
	data.FileSize = m_file->GetSize();

	for (const auto& strategy : m_roateStrategy)
	{
		if (strategy->NeedToRotate(data)) return true;
	}

	return false;
}

void LogArchive::Rotate(std::shared_ptr<LogFile>& curFile)
{
	Transfer(curFile);
	
	if (FilePathMaker::ChangeDateDirectory(curFile)) curFile->CreateDirectories();
}

void LogArchive::Transfer(const std::shared_ptr<LogFile>& file)
{
	if (file == nullptr) return;

	file->Close();

	std::string path = FilePathMaker::TransferPath(file->GetFilePath());
	if (rename(file->GetFilePath().c_str(), path.c_str()) != 0)
	{
		std::stringstream err;
		char buff[MAX_PATH]{};
		err << "rename fail" << strerror_s(buff, MAX_PATH, errno);
		throw std::runtime_error(err.str());
	}
}