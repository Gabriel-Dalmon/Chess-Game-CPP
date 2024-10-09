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

#ifdef _LOG
#include "Utilities/Logger.h"

namespace log_version_globals {
	// Declared in Utilities.cpp.
	extern bool isInitialized;
	extern Logger logger;
}

#define CREATE_LOGGER(file_path) log_version_globals::isInitialized = (log_version_globals::logger.Initialize(std::move(file_path), LoggerMode::KEEP_LOG_OPENED) == 0);

#define LOG(log_data)	if(log_version_globals::isInitialized == false) [[unlikely]] CREATE_LOGGER(const_cast<char*>("log.txt")); \
						log_version_globals::logger.Log(log_data);

#define DESTROY_LOGGER()	log_version_globals::logger.Release(); \
							log_version_globals::isInitialized = false;
#else
#define CREATE_LOGGER()
#define LOG()
#define DESTROY_LOGGER()
#endif