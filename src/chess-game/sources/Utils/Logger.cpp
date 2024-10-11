#include "pch.h"

//------------------------------------------------------------------------------
Logger::Logger() : m_p_file(nullptr)
{
}

//------------------------------------------------------------------------------
Logger::~Logger()
{
}

//------------------------------------------------------------------------------
int Logger::Initialize(const char* log_output_path, LoggerModes mode)
{
	m_p_file = new File();
	if(m_p_file->Open(log_output_path, "wb+") == false) return 1;
	return 0;
}

int Logger::Initialize(const char*&& log_output_path, LoggerModes mode)
{
	m_p_file = new File();
	if (m_p_file->Open(log_output_path, "wb+") == false) return 1;
	return 0;
}

//------------------------------------------------------------------------------
void Logger::Release()
{
	if (m_p_file != nullptr) {
		m_p_file->Release();
		delete m_p_file;
		m_p_file = nullptr;
	}
}

//------------------------------------------------------------------------------
void Logger::Log(const char* log_data)
{
	size_t data_length = strlen(log_data);
	m_p_file->Write((unsigned char*)log_data, data_length);
}
