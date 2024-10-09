#pragma once

//------------------------------------------------------------------------------
/* External includes */
#if defined(_SFML_VERSION)
#include <optional>
#include <SFML/Graphics/RenderWindow.hpp>
#elif defined(_GDI_VERSION)
#else
#endif

//------------------------------------------------------------------------------
/* Forward declarations
*
* graphics_wrapper is a namespace alias for graphic libraries wrapper objects
* that adapts to the namespace used by the loaded wrappers. */
//------------------------------------------------------------------------------
namespace graphics_wrapper {
	class Shape;
	class Sprite;
	class Text;
	class Texture;
	class Window;

	class Renderer;
}

//------------------------------------------------------------------------------
/* Includes */
#if defined(_SFML_VERSION)
#include "Graphics/SFML/Window.h"
#include "Graphics/SFML/Shape.h"
#include "Graphics/SFML/Sprite.h"
#include "Graphics/SFML/Text.h"
#include "Graphics/SFML/Texture.h"
#include "Graphics/SFML/Renderer.h"
#elif defined(_GDI_VERSION)
#include "Graphics/GDI/Renderer.h"
#else
#include "Graphics/Console/Renderer.h"
#endif