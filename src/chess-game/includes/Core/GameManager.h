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
	void UpdateDeltaTime();

private:
	GameManager();
	static GameManager* s_instance;
	Renderer m_renderer;
	EventsManager m_events_manager;

	Board* m_p_board;
	bool m_is_game_over;
	Clock m_clock;
	uint32_t m_delta_time = 0;
};

