#include "LogFile.h"
#include "IRotateStrategy.h"
#include "RotateData.h"
#include "TimeUtil.h"
#include "LogArchive.h"
#include <iostream>
#include "FileChannel.h"

FileChannel::FileChannel(const std::string& path) : m_file{ nullptr }, m_path{ path }
{}

void FileChannel::RegisterRotateStrategy(std::unique_ptr<IRotateStrategy> strategy)
{
	m_roateStrategy.push_back(std::move(strategy));
}

void FileChannel::Log(const LogLevel& level, const std::string& fmt)
{
	try
	{
		FileOpen();
		if (NeedToRotate()) Rotate();
		
		m_file->Write(fmt);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}

void FileChannel::FileOpen()
{
	if (m_file == nullptr)
	{
		m_file = std::make_shared<LogFile>(m_path);

		if (m_file->IsExist()) m_archive->Transfer(m_file);

		m_file->CreateDirectories();
	}
}

bool FileChannel::NeedToRotate()
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

void FileChannel::Rotate()
{
	m_archive->Rotate(m_file);
}