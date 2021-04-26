#include "LogFile.h"
#include "LogArchive.h"
#include <iostream>
#include "FileChannel.h"

void FileChannel::RegisterArchive(std::unique_ptr<LogArchive> archive)
{
	m_archive = std::move(archive);
}

void FileChannel::Log(const LogLevel& level, const std::string& fmt)
{
	try
	{
		if (m_archive == nullptr) throw std::runtime_error("archive is null \n");

		auto file = m_archive->Request();
		file->Write(fmt);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}