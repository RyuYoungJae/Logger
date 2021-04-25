#include "LogFile.h"
#include "FilePathMaker.h"
#include <sstream>
#include "LogArchive.h"

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