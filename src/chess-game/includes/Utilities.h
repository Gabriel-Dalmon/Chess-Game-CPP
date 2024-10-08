#pragma once

// External Includes
#include <stdio.h>

// Forward declarations
class File;
class Logger;
class Helper;

// Includes
#include "Utilities/File.h"
#include "Utilities/Logger.h"
#include "Utilities/Helper.h"

#define _LOG
#ifdef _LOG
#include "Utilities/Logger.h"

extern bool isInitializedEyJhbGciOiJI;
extern Logger loggerEyJhbGciOiJI;

#define CREATE_LOGGER(output_file_name) \
										size_t file_path_length = strlen(RESOURCES_PATH); \
										size_t file_name_length = strlen(output_file_name); \
										char* file_path = new char[file_path_length + file_name_length]; \
										memcpy(file_path, RESOURCES_PATH, file_path_length); \
										memcpy(file_path + file_path_length, output_file_name, file_name_length); \
										isInitializedEyJhbGciOiJI = (loggerEyJhbGciOiJI.Initialize(file_path, LoggerMode::KEEP_LOG_OPENED) == 0); \
										delete[] file_path;

#define LOG(log_data)	loggerEyJhbGciOiJI.Log(log_data);

#define DESTROY_LOGGER()	loggerEyJhbGciOiJI.Release(); \
							isInitializedEyJhbGciOiJI = false;
#else
#define CREATE_LOGGER()
#define LOG()
#define DESTROY_LOGGER()
#endif