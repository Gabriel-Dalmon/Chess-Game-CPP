#pragma once

// External includes
#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <typeinfo> 

//Forward declarations
#if defined(_SFML_VERSION)
class SFMLRenderer;
using Renderer = SFMLRenderer;
#elif defined(_GDI_VERSION)
class GDIRenderer;
using Renderer = GDIRenderer;
#else
class ConsoleRenderer;
using Renderer = ConsoleRenderer;
#endif

class GameManager;

// Includes
#if defined(_SFML_VERSION)
#include "Core/SFMLRenderer.h"
#elif defined(_GDI_VERSION)
#include "Core/GDIRenderer.h"
#else
#include "Core/ConsoleRenderer.h"
#endif

#include "Core/GameManager.h"