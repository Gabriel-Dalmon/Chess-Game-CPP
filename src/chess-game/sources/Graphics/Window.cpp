#include "pch.h"

Window::Window()
{
}

Window::~Window()
{
}

int Window::Initialize(int size[2], const char* title)
{
	p_window = new sf::RenderWindow(sf::VideoMode(size[0], size[1]), title);
	return 0;
}

void Window::Release()
{
	p_window->close();
}
