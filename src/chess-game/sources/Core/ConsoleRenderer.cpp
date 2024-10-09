#include "pch.h"
#if (defined(_SFML_VERSION) || defined(_GDI_VERSION)) == false
ConsoleRenderer::ConsoleRenderer()
{
}

ConsoleRenderer::~ConsoleRenderer()
{
}

int ConsoleRenderer::Initialize()
{
	return 0;
}

void ConsoleRenderer::Release()
{
}

void ConsoleRenderer::Render(const Board& board)
{
	const APiece* const* grid = board.GetGrid();

	std::cout << std::endl << m_reset_color << " /=";
	for (int column = 1; column <= BOARD_WIDTH; column++) {
		std::cout << "|" << column << "|";
	}
	std::cout << "=\\ " << std::endl;
	for (int row = 0; row < BOARD_HEIGHT; row++)
	{
		std::cout << " |" << m_rows[row];
		for (int column = 0; column < BOARD_WIDTH; column++)
		{
			const APiece* p_piece = grid[column + row * BOARD_WIDTH];
			std::cout << (column ? " " : "|");
			if (p_piece == nullptr)
			{
				std::cout << "-";
			}
			else
			{
				char piece_display = m_pieces_display_map.at(std::type_index(p_piece->GetType()));
				const char* color = p_piece->GetColor() == PieceColor::WHITE ? m_green_color : m_purple_color;
				std::cout << color << piece_display << m_reset_color;
			}
			std::cout << (column == BOARD_WIDTH - 1 ? "|" : " ");
		}
		std::cout << m_rows[row] << "| " << std::endl;
	}
	std::cout << " \\=";
	for (int column = 1; column <= BOARD_WIDTH; column++) {
		std::cout << "|" << column << "|";
	}
	std::cout << "=/ " << std::endl << std::endl;
	return;
}

#endif