#include "pch.h"

//------------------------------------------------------------------------------
File::File() : m_size(0), m_path(nullptr), m_pFile(nullptr) {
}

//------------------------------------------------------------------------------
bool File::Open(const char* path, const char* openMode) {
	m_pFile = nullptr;
	delete[] m_path;

	size_t path_length = std::strlen(path) + 1;
	m_path = new char[path_length];
	memcpy_s(m_path, path_length, path, path_length);
	
	fopen_s(&m_pFile, m_path, openMode);
	if (m_pFile == nullptr) {
		return false;
	}
	fseek(m_pFile, 0, SEEK_END);
	m_size = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET);
	return true;
}

//------------------------------------------------------------------------------
bool File::Open(char*&& path, const char* openMode)
{
	m_pFile = nullptr;
	delete[] m_path;
	m_path = path;
	path = nullptr;

	fopen_s(&m_pFile, path, openMode);
	if (m_pFile == nullptr) {
		return false;
	}
	fseek(m_pFile, 0, SEEK_END);
	m_size = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET);
	return true;
	return true;
}

//------------------------------------------------------------------------------
bool File::Open(const wchar_t* path, const wchar_t* openMode) {
	//m_path = path;  wcstombs_s((size_t)0, m_path, path, (size_t)_TRUNCATE);
	_wfopen_s(&m_pFile, path, openMode);
	if (m_pFile == nullptr) {
		return false;
	}
	fseek(m_pFile, 0, SEEK_END);
	m_size = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET);
	return true;
}

//------------------------------------------------------------------------------
long int File::GetSize() {
	return m_size;
}

//------------------------------------------------------------------------------
void File::Read(Byte* buffer) {
	if (m_pFile != nullptr) {
		fseek(m_pFile, 0, SEEK_SET);
		fread(buffer, sizeof(char), m_size, m_pFile);
	}
}

//------------------------------------------------------------------------------
void File::ReadChunk(Byte* buffer, int size)
{
	if (m_pFile != nullptr) {
		fread(buffer, sizeof(char), size, m_pFile);
	}
}

//------------------------------------------------------------------------------
void File::Write(Byte* buffer, int size) {
	m_size += size;
	if (m_pFile != nullptr) {
		fwrite(buffer, sizeof(Byte), m_size, m_pFile);
	}
}

//------------------------------------------------------------------------------
void File::SetCursor(long offset, int mode)
{
	fseek(m_pFile, offset, mode);
}

//------------------------------------------------------------------------------
void File::Close() {
	if (m_pFile != nullptr) {
		fclose(m_pFile);
		m_pFile = nullptr;
	}
}

//------------------------------------------------------------------------------
void File::Release()
{
	Close();
}
