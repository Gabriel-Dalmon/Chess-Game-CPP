#pragma once

class GameManager {
public:
	static GameManager& instance();
	~GameManager();

	int Initialize();
	int Run();
	void Release();

private:
	void CreatePawnsRow(PieceColor color, int row);
	void CreateMajorPiecesRow(PieceColor color, int row);
	void PlayRound();

private:
	GameManager();
	static GameManager* s_instance;
	Renderer* m_p_renderer;

	Board* m_p_board;
	bool m_is_game_over;
};

