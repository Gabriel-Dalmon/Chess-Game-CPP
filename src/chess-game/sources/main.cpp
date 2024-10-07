#include "pch.h"
#include "main.h"

int main()
{

	GameManager& gameManager = GameManager::instance();
	gameManager.Initialize();
	gameManager.Run();
	gameManager.Release();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}