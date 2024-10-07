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
	void PlayRound();
	void DrawBoard();

private:
	GameManager();
	static GameManager* s_instance;

	Board* m_board;
	bool m_is_game_over;
	static const std::unordered_map<std::type_index, char> s_pieces_display_map;
};

