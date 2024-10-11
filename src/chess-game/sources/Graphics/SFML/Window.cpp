#include "pch.h"

namespace sfmlw {
//------------------------------------------------------------------------------
Window::Window()
{
}

//------------------------------------------------------------------------------
Window::~Window()
{
}

//------------------------------------------------------------------------------
int Window::Initialize(const unsigned int size[2], const char* title)
{
	//--------------------------------------------------------------------------
	/* Currently purposedly didn't initialize m_window in constructor, safer 
	* implementation would either be to define it with aligned_storage (would 
	* require casting) or as an std::optional. Else it is maybe possible to
	* create some sort of compile time assertion that ensures other Window's
	* methods aren't called before Initialize is called. */
	//--------------------------------------------------------------------------
#undef new
	new (&m_window) sf::RenderWindow(sf::VideoMode(size[0], size[1]), title);
#define new DEBUG_NEW
	return 0;
}

//------------------------------------------------------------------------------
/* Shouldn't be called before Initialize is called as long as m_window remains
* unsafe. */
void Window::Release()
{
	m_window.close();
	m_window.~RenderWindow();
}

//------------------------------------------------------------------------------
void Window::Draw(const sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void Window::Clear(const sf::Color& color)
{
	m_window.clear(color);
}

//------------------------------------------------------------------------------
void Window::Clear()
{
	m_window.clear();
}

}