#pragma once

// External includes
#if defined(_SFML_VERSION)
#include <SFML/Graphics/RenderWindow.hpp>
#elif defined(_GDI_VERSION)
#else
#endif

// Forward Declarations
class Window;

// Includes
#include "Graphics/Window.h"