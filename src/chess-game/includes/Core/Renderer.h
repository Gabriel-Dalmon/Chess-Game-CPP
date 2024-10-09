#pragma once
#ifdef INCLUDE_SFML

//------------------------------------------------------------------------------
namespace sfmlw {

//------------------------------------------------------------------------------
class Renderer {
public:
	Renderer();
	~Renderer();

	int Initialize();
	void Release();

	void Render(const Board& board);
private:
	Window* p_window;
};

}
#endif