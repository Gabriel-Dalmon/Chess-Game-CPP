#pragma once

//------------------------------------------------------------------------------
/* Setup the objects instantiations registrations to track memory leaks */
//------------------------------------------------------------------------------
#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif

//------------------------------------------------------------------------------
/*	- Define an include macro to specify which files content should be defined -
*	  based on the configuration version.
*	- Define a namespace alias meant to contain all forward declarations in
*	  instead of having to redefine them all for their specific namespace. */
//------------------------------------------------------------------------------
#if defined(_SFML_VERSION)
#define INCLUDE_SFML
namespace sfmlw {}
namespace engine_wrapper {
	using namespace sfmlw;
}
using namespace sfmlw;
#elif defined(_GDI_VERSION)
#define INCLUDE_GDI
namespace gdiw {}
namespace engine_wrapper {
	using namespace gdiw;
}
using namespace gdiw;
#else
#define INCLUDE_CONSOLE
namespace consolew {}
namespace graphics_namespace {
	using namespace consolew;
}
using namespace consolew;
#endif

//------------------------------------------------------------------------------
/* Define the path to the resources folder */
#ifdef _DEBUG
#define RESOURCES_PATH "../../../res/"
#else
#define RESOURCES_PATH "./"
#endif

//------------------------------------------------------------------------------
/* Includes */
#include "Utilities.h"
#include "Chess.h"
#include "Graphics.h"
#include "Events.h"
#include "Core.h"
