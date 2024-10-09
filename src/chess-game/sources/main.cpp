#include "pch.h"
#include "main.h"


int main()
{
	CREATE_LOGGER(const_cast<char*>("output.txt"));

	GameManager& gameManager = GameManager::instance();
	gameManager.Initialize();
	gameManager.Run();
	gameManager.Release();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	DESTROY_LOGGER();
	return 0;
}