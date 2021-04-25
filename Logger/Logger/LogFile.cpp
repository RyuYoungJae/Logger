#include <fstream>
#include "LogFile.h"

LogFile::LogFile(const std::string& path) : m_file{ INVALID_HANDLE_VALUE }, m_path{ path }
{
}

LogFile::~LogFile()
{
	CloseHandle(m_file);
}

void LogFile::Write(const std::string& fmt)
{
	if (m_file == INVALID_HANDLE_VALUE) CreateLogFile();

	DWORD bytesWritten = 0;
	if (!WriteFile(m_file, fmt.c_str(), static_cast<DWORD>(fmt.length()), &bytesWritten, NULL)) throw std::runtime_error("Exception from file write \n");

	if (!FlushFileBuffers(m_file)) throw std::runtime_error("Exception from file flush \n");
}

int LogFile::GetSize()
{
	LARGE_INTEGER size{};
	GetFileSizeEx(m_file, &size);

	return static_cast<int>(size.QuadPart);
}

bool LogFile::IsExist()
{
	std::ifstream fs(m_path);
	return fs.good();
}

void LogFile::CreateLogFile()
{
	CreateDirectories();

	m_file = CreateFileA(m_path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_file == INVALID_HANDLE_VALUE) throw std::runtime_error("Exception from file create \n");
}

void LogFile::CreateDirectories()
{
	if (IsExistDirectories()) return;
	
	size_t pos = 0;
	while (pos != std::wstring::npos)
	{
		pos = m_path.find_first_of("\\/", pos + 1);
		if (pos != std::wstring::npos) CreateDirectory(m_path.substr(0, pos).c_str(), NULL);
	}
}

bool LogFile::IsExistDirectories()
{
	auto attrib = GetFileAttributesA(m_path.c_str());

	return (attrib != INVALID_FILE_ATTRIBUTES &&
		(attrib & FILE_ATTRIBUTE_DIRECTORY));
}

void LogFile::Close()
{
	if (m_file == INVALID_HANDLE_VALUE) return;

	FlushFileBuffers(m_file);
	CloseHandle(m_file);
	m_file = INVALID_HANDLE_VALUE;
}

const std::string& LogFile::GetFilePath()
{
	return m_path;
}

void LogFile::ChangeFilePath(const std::string& path)
{
	m_path = path;
}
