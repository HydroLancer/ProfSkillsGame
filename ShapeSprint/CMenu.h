#pragma once
#include "ControlHeader.h"

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

public:
	CMenu();
	void MenuSetup(I3DEngine* myEngine);
	void MenuUpdate(I3DEngine* myEngine, gameState& state);

	void CloseDown(I3DEngine* myEngine);

	void DrawAllSprites(I3DEngine* myEngine);

	~CMenu();
};
