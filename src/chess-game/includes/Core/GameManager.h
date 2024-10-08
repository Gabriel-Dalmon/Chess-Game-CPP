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
	const std::unordered_map<std::type_index, char> m_pieces_display_map = {
		{std::type_index(typeid(Pawn)), 'P'},
		{std::type_index(typeid(Rook)), 'R'},
		{std::type_index(typeid(Knight)), 'K'},
		{std::type_index(typeid(Bishop)), 'B'}
	};
};

