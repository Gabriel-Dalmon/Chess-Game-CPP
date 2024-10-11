#include "pch.h"
#ifdef INCLUDE_SFML

//------------------------------------------------------------------------------
sfmlw::Renderer::Renderer() : 
	m_window(), 
	m_dark_tile(nullptr), 
	m_board_color_light(255,255,255,255), 
	m_board_color_dark()
{
}

//------------------------------------------------------------------------------
sfmlw::Renderer::~Renderer()
{
}

//------------------------------------------------------------------------------
int sfmlw::Renderer::Initialize()
{
	const unsigned int size[2] = { 800, 600 };
	m_window.Initialize(size, "Chess Game C++");
	m_dark_tile = new SquareShape();
	const int tile_length = std::min(m_window.GetWidth(), m_window.GetHeight()) / 8;
	m_dark_tile->Initialize(tile_length, m_board_color_dark);
	return 0;
}

//------------------------------------------------------------------------------
void sfmlw::Renderer::Release()
{
	m_window.Release();
}

//------------------------------------------------------------------------------
void sfmlw::Renderer::Render(const Board& board)
{
	m_window.Clear(m_board_color_light);
	const APiece* const* grid = board.GetGrid();
	const unsigned int grid_width = board.GetGridWidth();
	const unsigned int grid_height = board.GetGridHeight();
	const unsigned int tile_length = m_dark_tile->GetLength();
	const unsigned window_width = m_window.GetWidth();
	const unsigned window_height = m_window.GetHeight();

	const int is_window_width_longer = 
		static_cast<int>(window_width > window_height);

	const int is_window_height_longer = 1 - is_window_width_longer;

	const unsigned int padding_left = 
		is_window_width_longer * (window_width - window_height) / 2;
	const unsigned int padding_top =
		is_window_height_longer * (window_height - window_width) / 2;

	for (int row = 0; row < grid_width; row++) {
		for (int column = 1; column < grid_height / 2; column += 2) {
			const unsigned int tile_position_x = padding_left + column * tile_length;
			const unsigned int tile_position_y = padding_top + row * tile_length;
			m_dark_tile->SetPosition(tile_position_x, tile_position_y);
			//m_window.DrawShape(m_dark_tile);

	for (int row = 0; row < grid_width; row++) {
		for (int column = 0; column < grid_height; column++) {
			/*const int square_index = column + row * grid_width;
			if (grid[square_index] != nullptr) {
				Sprite* sprite = m_piece_sprites[grid[square_index]->GetType();
				m_window.Draw();
			}*/
		}
	}
	//window.Draw();
	//window.Display();
}

#endif