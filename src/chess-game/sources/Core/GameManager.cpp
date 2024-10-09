#include "pch.h"

GameManager* GameManager::s_instance = nullptr;

GameManager& GameManager::instance()
{
	if (!s_instance) {
		s_instance = new GameManager();
	};
	return *s_instance;
}

GameManager::GameManager() : /*m_p_renderer(nullptr),*/ m_p_board(nullptr), m_is_game_over(false)
{
}

GameManager::~GameManager()
{
}

int GameManager::Initialize()
{
	// m_p_renderer = new Renderer();
	// m_p_renderer->Initialize();
	m_p_board = new Board();
	m_p_board->CreatePiece<Rook>(PieceColor::WHITE, 0, BOARD_HEIGHT - 1);
	m_p_board->CreatePiece<Rook>(PieceColor::WHITE, BOARD_WIDTH - 1, BOARD_HEIGHT - 1);
	m_p_board->CreatePiece<Knight>(PieceColor::WHITE, 1, BOARD_HEIGHT - 1);
	m_p_board->CreatePiece<Knight>(PieceColor::WHITE, BOARD_WIDTH - 2, BOARD_HEIGHT - 1);
	m_p_board->CreatePiece<Bishop>(PieceColor::WHITE, 2, BOARD_HEIGHT - 1);
	m_p_board->CreatePiece<Bishop>(PieceColor::WHITE, BOARD_WIDTH - 3, BOARD_HEIGHT - 1);
	CreatePawnsRow(PieceColor::WHITE, BOARD_HEIGHT - 2);

	m_p_board->CreatePiece<Rook>(PieceColor::BLACK, 0, 0);
	m_p_board->CreatePiece<Rook>(PieceColor::BLACK, BOARD_WIDTH - 1, 0);
	m_p_board->CreatePiece<Knight>(PieceColor::BLACK, 1, 0);
	m_p_board->CreatePiece<Knight>(PieceColor::BLACK, BOARD_WIDTH - 2, 0);
	m_p_board->CreatePiece<Bishop>(PieceColor::BLACK, 2, 0);
	m_p_board->CreatePiece<Bishop>(PieceColor::BLACK, BOARD_WIDTH - 3, 0);
	CreatePawnsRow(PieceColor::BLACK, 1);
	return 0;
}

int GameManager::Run()
{
	while(m_is_game_over == false)
	{
		//m_p_renderer->Render(*m_p_board);
		PlayRound();
	}
	return 0;
}

void GameManager::Release()
{
	if (m_p_board != nullptr)
	{
		m_p_board->Release();
		delete m_p_board;
		m_p_board = nullptr;
	}
}

void GameManager::CreatePawnsRow(PieceColor color, int row)
{
	for (int column = 0; column < BOARD_WIDTH; column++)
	{
		m_p_board->CreatePiece<Pawn>(color, column, row);
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

		MoveInfo* p_move = m_p_board->Move(start_position, destination_position);
		if (p_move == nullptr)
		{
			//m_p_renderer->Render(*m_p_board);
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
