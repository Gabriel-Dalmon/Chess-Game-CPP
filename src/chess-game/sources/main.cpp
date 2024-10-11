#include "pch.h"
#include "main.h"

//------------------------------------------------------------------------------
int main()
{
	//-------------------------------------------------------------------------
	CREATE_LOGGER(const_cast<char*>("output.txt"));

	//-------------------------------------------------------------------------
	GameManager& gameManager = GameManager::instance();
	gameManager.Initialize();
	gameManager.Run();
	gameManager.Release();
	auto a = 1 <=> 2;
	//-------------------------------------------------------------------------
	DESTROY_LOGGER();
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}