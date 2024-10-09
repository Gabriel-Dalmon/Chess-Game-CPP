#pragma once
#if (defined(_SFML_VERSION) || defined(_GDI_VERSION)) == false

class ConsoleRenderer {
public:
	ConsoleRenderer();
	~ConsoleRenderer();

	int Initialize();
	void Release();

	void Render(const Board& board);
private:
	const char* m_purple_color = "\033[35m";  // Purple (magenta)
	const char* m_green_color = "\033[32m";   // Green
	const char* m_reset_color = "\033[0m";     // Reset to default color
	const char* m_rows = "abcdefgh";
	const std::unordered_map<std::type_index, char> m_pieces_display_map = {
		{std::type_index(typeid(Pawn)), 'P'},
		{std::type_index(typeid(Rook)), 'R'},
		{std::type_index(typeid(Knight)), 'K'},
		{std::type_index(typeid(Bishop)), 'B'}
	};
};

#endif