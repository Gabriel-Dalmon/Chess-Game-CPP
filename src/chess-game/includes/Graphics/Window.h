#pragma once
#ifdef _SFML_VERSION

class Window {
	Window();
	~Window();

	int Initialize(int size[2], const char* title);
	void Release();

	sf::RenderWindow* p_window;
};

#endif