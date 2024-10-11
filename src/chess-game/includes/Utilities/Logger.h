#pragma once
#ifdef _LOG

//------------------------------------------------------------------------------
typedef enum LoggerModes {
	KEEP_LOG_OPENED
} LoggerMode;

//------------------------------------------------------------------------------
class Logger {
public:
	Logger();
	~Logger();

	int Initialize(const char* log_output_path, LoggerModes mode);
	int Initialize(const char*&& log_output_path, LoggerModes mode);
	void Release();

	void Log(const char* log_data);

private:
	File* m_p_file;
};

#endif