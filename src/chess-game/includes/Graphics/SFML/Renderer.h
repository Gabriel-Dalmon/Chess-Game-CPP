#pragma once
#ifdef INCLUDE_SFML

//------------------------------------------------------------------------------
namespace sfmlw {

//------------------------------------------------------------------------------
class Renderer {
public:
	Renderer();
	~Renderer();

	int Initialize();
	void Release();

	void Render(const Board& board);
private:
	Window m_window;
	Sprite* m_piece_sprites[9];
	SquareShape* m_dark_tile;
	sf::Color m_board_color_light;
	sf::Color m_board_color_dark;
};

}
#endif