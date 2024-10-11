#include "pch.h"

//------------------------------------------------------------------------------
GameManager* GameManager::s_instance = nullptr;

//------------------------------------------------------------------------------
GameManager& GameManager::instance()
{
	if (!s_instance) {
		s_instance = new GameManager();
	};
	return *s_instance;
}

//------------------------------------------------------------------------------
GameManager::GameManager() : m_renderer(), m_events_manager(), m_p_board(nullptr), m_is_game_over(false)
{
}

//------------------------------------------------------------------------------
GameManager::~GameManager()
{
}

//------------------------------------------------------------------------------
int GameManager::Initialize()
{
	m_renderer.Initialize();
	m_events_manager.Initialize();

	m_p_board = new Board();
	m_p_board->Initialize();

	CreateMajorPiecesRow(PieceColor::WHITE, BOARD_HEIGHT - 1);
	CreatePawnsRow(PieceColor::WHITE, BOARD_HEIGHT - 2);
	CreateMajorPiecesRow(PieceColor::BLACK, 0);
	CreatePawnsRow(PieceColor::BLACK, 1);
	return 0;
}

//------------------------------------------------------------------------------
int GameManager::Run()
{
	while(m_is_game_over == false)
	{
		m_renderer.Render(*m_p_board);
		PlayRound();
	}
	return 0;
}

//------------------------------------------------------------------------------
void GameManager::Release()
{
	if (m_p_board != nullptr)
	{
		m_p_board->Release();
		delete m_p_board;
		m_p_board = nullptr;
	}
	m_renderer.Release();
	m_events_manager.Release();
}

//------------------------------------------------------------------------------
void GameManager::CreatePawnsRow(PieceColor color, int row)
{
	for (int column = 0; column < BOARD_WIDTH; column++)
	{
		m_p_board->CreatePiece<Pawn>(color, column, row);
	}
	return;
}

//------------------------------------------------------------------------------
void GameManager::CreateMajorPiecesRow(PieceColor color, int row)
{
	m_p_board->CreatePiece<Rook>(color, 0, row);
	m_p_board->CreatePiece<Rook>(color, BOARD_WIDTH - 1, row);
	m_p_board->CreatePiece<Knight>(color, 1, 0);
	m_p_board->CreatePiece<Knight>(color, BOARD_WIDTH - 2, row);
	m_p_board->CreatePiece<Bishop>(color, 2, 0);
	m_p_board->CreatePiece<Bishop>(color, BOARD_WIDTH - 3, row);
	m_p_board->CreatePiece<Queen>(color, 3, row);
	m_p_board->CreatePiece<King>(color, 4, row);
	return;
}

//------------------------------------------------------------------------------
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

		MoveInfo* p_move =
			m_p_board->Move(start_position, destination_position);
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

void GameManager::UpdateDeltaTime()
{
	m_delta_time = m_clock.GetElapsedTime();
	m_clock.Reset();
}
