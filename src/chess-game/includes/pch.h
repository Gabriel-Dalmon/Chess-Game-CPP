#pragma once

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif

#ifdef _DEBUG
#define RESOURCES_PATH "../../../res/"
#else
#define RESOURCES_PATH "./"
#endif

#ifdef _SFML_VERSION
#define INCLUDE_SFML
namespace sfmlw {
	struct Empty { int x = 0; };
}
namespace graphics_namespace = sfmlw;
#endif


// Includes
#include "Utilities.h"
#include "Graphics.h"
#include "Chess.h"
#include "Core.h"