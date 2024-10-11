#include "pch.h"
#ifdef INCLUDE_SFML

namespace sfmlw {

//------------------------------------------------------------------------------
Renderer::Renderer()
{
}

//------------------------------------------------------------------------------
Renderer::~Renderer()
{
}

//------------------------------------------------------------------------------
int Renderer::Initialize()
{
#undef new
	new (&window) Window();
#define new DEBUG_NEW
	const unsigned int size[2] = { 800, 600 };
	window.Initialize(size, "Chess Game C++");
	return 0;
}

//------------------------------------------------------------------------------
void Renderer::Release()
{
}

//------------------------------------------------------------------------------
void Renderer::Render(const Board& board)
{
	window.Clear();
	//window.Draw();
	//window.Display();
}

}
#endif