#pragma once

//------------------------------------------------------------------------------
// External Includes
#if defined(_SFML_VERSION)
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#elif defined(_GDI_VERSION)
#else
#endif

#include <stdio.h>

//------------------------------------------------------------------------------
// Forward declarations
#ifdef _LOG
class Logger
#endif
namespace engine_wrapper {
	class Clock;
}

class File;
class Helper;

//------------------------------------------------------------------------------
/* Includes */
//------------------------------------------------------------------------------
#ifdef _LOG
#include "Utilities/Logger.h"
#endif

//------------------------------------------------------------------------------
#if defined(_SFML_VERSION)
#include "Utilities/SFML/Clock.h"
#elif defined(_GDI_VERSION)
#include "Utilities/GDI/Clock.h"
#else
#include "Utilities/Console/Clock.h"
#endif

//------------------------------------------------------------------------------
#include "Utilities/File.h"
#include "Utilities/Helper.h"

//------------------------------------------------------------------------------
#ifdef _LOG
#include "Utilities/Logger.h"

//------------------------------------------------------------------------------
namespace log_version_globals {
	// Declared in Utilities.cpp.
	extern bool isInitialized;
	extern Logger logger;
}

//------------------------------------------------------------------------------
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