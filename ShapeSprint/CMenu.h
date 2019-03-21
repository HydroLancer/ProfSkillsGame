#pragma once
#include "ControlHeader.h"

class CMenu
{
private:
	IMesh* screenMesh;
	IModel* screen;

	
	int position;
	bool isDead;

public:
	CMenu();
	void MenuSetup(I3DEngine* myEngine);
	void MenuUpdate(I3DEngine* myEngine, gameState& state);

	void CloseDown();

	~CMenu();
};
