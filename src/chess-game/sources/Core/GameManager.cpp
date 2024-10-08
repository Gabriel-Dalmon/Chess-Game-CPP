#include "pch.h"

GameManager* GameManager::s_instance = nullptr;

GameManager& GameManager::instance()
{
	if (!s_instance) {
		s_instance = new GameManager();
	};
	return *s_instance;
}

GameManager::GameManager() : m_board(nullptr), m_is_game_over(false)
{
}

GameManager::~GameManager()
{
}

int GameManager::Initialize()
{
	m_board = new Board();
	m_board->CreatePiece<Rook>(PieceColor::WHITE, 0, BOARD_HEIGHT - 1);
	m_board->CreatePiece<Rook>(PieceColor::WHITE, BOARD_WIDTH - 1, BOARD_HEIGHT - 1);
	m_board->CreatePiece<Knight>(PieceColor::WHITE, 1, BOARD_HEIGHT - 1);
	m_board->CreatePiece<Knight>(PieceColor::WHITE, BOARD_WIDTH - 2, BOARD_HEIGHT - 1);
	m_board->CreatePiece<Bishop>(PieceColor::WHITE, 2, BOARD_HEIGHT - 1);
	m_board->CreatePiece<Bishop>(PieceColor::WHITE, BOARD_WIDTH - 3, BOARD_HEIGHT - 1);
	CreatePawnsRow(PieceColor::WHITE, BOARD_HEIGHT - 2);

	m_board->CreatePiece<Rook>(PieceColor::BLACK, 0, 0);
	m_board->CreatePiece<Rook>(PieceColor::BLACK, BOARD_WIDTH - 1, 0);
	m_board->CreatePiece<Knight>(PieceColor::BLACK, 1, 0);
	m_board->CreatePiece<Knight>(PieceColor::BLACK, BOARD_WIDTH - 2, 0);
	m_board->CreatePiece<Bishop>(PieceColor::BLACK, 2, 0);
	m_board->CreatePiece<Bishop>(PieceColor::BLACK, BOARD_WIDTH - 3, 0);
	CreatePawnsRow(PieceColor::BLACK, 1);
	return 0;
}

int GameManager::Run()
{
	while(m_is_game_over == false)
	{
		DrawBoard();
		PlayRound();
	}
	return 0;
}

void GameManager::Release()
{
	if (m_board != nullptr)
	{
		m_board->Release();
		delete m_board;
		m_board = nullptr;
	}
}

void GameManager::CreatePawnsRow(PieceColor color, int row)
{
	for (int column = 0; column < BOARD_WIDTH; column++)
	{
		m_board->CreatePiece<Pawn>(color, column, row);
	}
	return;
}

void GameManager::PlayRound()
{
	bool is_valid_move = true;
	do {
		std::cout << "Enter the piece coordinates you want to move: ";
		int start_position[2];
		std::cin >> start_position[0] >> start_position[1];
		start_position[0]--; // Reset to 0-based index
		start_position[1]--; // Reset to 0-based index

		std::cout << "Enter the destination position: ";
		int destination_position[2];
		std::cin >> destination_position[0] >> destination_position[1];
		destination_position[0]--; // Reset to 0-based index
		destination_position[1]--; // Reset to 0-based index

		system("cls");

		MoveInfo* p_move = m_board->Move(start_position, destination_position);
		if (p_move == nullptr)
		{
			DrawBoard();
			std::cout << "Invalid move. Try again." << std::endl;
			continue;
		}
		// Check if the move is a capture
		if (p_move->captured_piece != nullptr)
		{
			std::cout << "Piece captured!" << std::endl;
		}
		delete p_move;
		is_valid_move = false;
	} while (is_valid_move);
	return;
}

void GameManager::DrawBoard()
{
	const char* purple_color = "\033[35m";  // Purple (magenta)
	const char* green_color = "\033[32m";   // Green
	const char* reset_color = "\033[0m";     // Reset to default color
	const char* rows = "abcdefgh";
	std::cout << std::endl << " /=";
	for (int column = 1; column <= BOARD_WIDTH; column++) 	{
		std::cout << "|" << column << "|";
	}
	std::cout << "=\\ " << std::endl;
	for(int row = 0; row < BOARD_HEIGHT; row++)
	{
		std::cout << " |" << rows[row];
		for (int column = 0; column < BOARD_WIDTH; column++)
		{
			const APiece* p_piece = m_board->GetGrid()[column + row * BOARD_WIDTH];
			std::cout << (column ? " " : "|");
			if (p_piece == nullptr)
			{
				std::cout << "-";
			}
			else
			{
				char piece_display = 'P';//s_pieces_display_map.at(std::type_index(p_piece->GetType()));
				const char* color = p_piece->GetColor() == PieceColor::WHITE ? green_color : purple_color;
				std::cout << color << piece_display << reset_color;
			}
			std::cout << (column == BOARD_WIDTH - 1 ? "|" : " ");
		}
		std::cout << rows[row] << "| " << std::endl;
	}
	std::cout << " \\=";
	for (int column = 1; column <= BOARD_WIDTH; column++) {
		std::cout << "|" << column << "|";
	}
	std::cout << "=/ " << std::endl << std::endl;
	return;
}
