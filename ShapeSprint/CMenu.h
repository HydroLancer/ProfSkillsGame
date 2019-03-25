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

	ISprite* logo;
	ISprite* menuSprite;
	
	int position;
	
	bool isDead;
	bool spriteDrawn;

	menuThing menuState;

public:
	CMenu();
	void MenuSetup(I3DEngine* myEngine);
	void MenuUpdate(I3DEngine* myEngine, gameState& state);

	void CloseDown(I3DEngine* myEngine);


	void GameSetup(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine, gameState& state);

	~CMenu();
	void MenuSystem(CGameMap * function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine * myEngine, gameState& state, ICamera* myCamera);
};