#include "pch.h"
#include "main.h"

int main()
{
	CREATE_LOGGER("output.txt");
	LOG("Test Data to Log2");
	DESTROY_LOGGER();
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif


	GameManager& gameManager = GameManager::instance();
	gameManager.Initialize();
	gameManager.Run();
	gameManager.Release();

	return 0;

}