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
	
	struct SPlayButton
	{
		ISprite* flat;
		ISprite* hover;
	};
	
	struct SLevelsButton
	{
		ISprite* flat;
		ISprite* hover;
	};

	struct SOptionsButton
	{
		ISprite* flat;
		ISprite* hover;
	};

	struct SExitButton
	{
		ISprite* flat;
		ISprite* hover;
	};

	SPlayButton play;
	SLevelsButton levels;
	SOptionsButton options;
	SExitButton exit;

	int position;
	bool isDead;
	menuThing menuState;

public:
	CMenu();
	void MenuSetup(I3DEngine* myEngine);
	void MenuUpdate(I3DEngine* myEngine, gameState& state);

	void CloseDown(I3DEngine* myEngine);

	void DrawAllSprites(I3DEngine* myEngine);

	void GameSetup(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine, gameState& state);

	~CMenu();
	void MenuSystem(CGameMap * function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
		int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine * myEngine, gameState& state, ICamera* myCamera);
};