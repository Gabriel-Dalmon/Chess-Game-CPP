#pragma once

//------------------------------------------------------------------------------
/* External includes */
#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <typeinfo> 

//------------------------------------------------------------------------------
/* Forward declarations 
* 
* graphics_wrapper is a namespace alias for graphic libraries wrapper objects 
* that adapts to the namespace used by the loaded wrappers. */
//------------------------------------------------------------------------------
namespace graphics_wrapper {
	class Renderer;
}

class GameManager;

//------------------------------------------------------------------------------
/* Includes */
#if defined(_SFML_VERSION)
#include "Core/Renderer.h"
using namespace sfmlw;
#elif defined(_GDI_VERSION)
#include "Core/GDIRenderer.h"
#else
#include "Core/ConsoleRenderer.h"
#endif

#include "Core/GameManager.h"