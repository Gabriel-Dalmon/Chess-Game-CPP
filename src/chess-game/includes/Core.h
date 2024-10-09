#pragma once

// External includes
#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <typeinfo> 

//Forward declarations
namespace graphics_namespace {
	class Renderer;
}
class GameManager;

// Includes
#if defined(_SFML_VERSION)
#include "Core/Renderer.h"
using namespace sfmlw;
#elif defined(_GDI_VERSION)
#include "Core/GDIRenderer.h"
#else
#include "Core/ConsoleRenderer.h"
#endif

#include "Core/GameManager.h"