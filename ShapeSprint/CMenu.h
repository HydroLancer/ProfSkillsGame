#pragma once
#include "ControlHeader.h"
#include "Sound.h"
#include "CGameMap.h"

enum menuThing { Start, InUse, Loading, CloseMenu };

class CMenu
{
private:
	IMesh* screenMesh;
	IModel* screen;

	int position;
	bool isDead;
	menuThing menuState;

public:
	CMenu();
	void MenuSetup(I3DEngine* myEngine);
	void MenuUpdate(I3DEngine* myEngine, gameState& state);

	void CloseDown();

	void GameSetup(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine);

	~CMenu();
	void MenuSystem(CGameMap * function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine * myEngine, gameState& state);
};