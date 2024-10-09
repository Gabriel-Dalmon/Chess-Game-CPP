#pragma once
#ifdef _SFML_VERSION

//------------------------------------------------------------------------------
namespace sfmlw {

//------------------------------------------------------------------------------
class Window {
public:
	Window();
	~Window();

	int Initialize(const int size[2], const char* title);
	void Release();

//------------------------------------------------------------------------------
private:
	sf::RenderWindow m_window;
};

}
#endif