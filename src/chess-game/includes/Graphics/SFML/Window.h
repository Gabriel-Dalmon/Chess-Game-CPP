#pragma once
#ifdef _SFML_VERSION

//------------------------------------------------------------------------------
namespace sfmlw {

//------------------------------------------------------------------------------
class Window {
public:
    Window();
    ~Window();

    int Initialize(const unsigned int size[2], const char* title);
    void Release();

    void Draw(const sf::Drawable& drawable);
    void Clear();

    inline unsigned int GetWidth() const { return m_window.getSize().x; };
    inline unsigned int GetHeight() const { return m_window.getSize().y; };

private:
    sf::RenderWindow m_window;
};

}
#endif