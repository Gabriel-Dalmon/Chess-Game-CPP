#pragma once

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif

#ifdef _DEBUG
#define RESOURCES_PATH "../../../res/"
#else
#define RESOURCES_PATH("./")
#endif

// Includes
#include "Utilities.h"
#include "Chess.h"
#include "Core.h"