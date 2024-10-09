#include "pch.h"
#ifdef INCLUDE_SFML

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
	const int size[2] = { 800, 600 };
	window.Initialize(size, "Chess");
	return 0;
}

//------------------------------------------------------------------------------
void Renderer::Release()
{
}

//------------------------------------------------------------------------------
void Renderer::Render(const Board& board)
{
}

#endif