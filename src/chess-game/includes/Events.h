#pragma once

//------------------------------------------------------------------------------
/* External includes */
#if defined(_SFML_VERSION)
#elif defined(_GDI_VERSION)
#else
#endif

//------------------------------------------------------------------------------
/* Forward declaration */
namespace engine_wrapper {
	class EventsManager;
}

//------------------------------------------------------------------------------
/* Includes */
#if defined(_SFML_VERSION)
#include "Events/SFML/EventsManager.h"
#elif defined(_GDI_VERSION)
#include "Events/GDI/EventsManager.h"
#else
#include "Events/Console/EventsManager.h"
#endif