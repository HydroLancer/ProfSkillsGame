#include "CMenu.h"

CMenu::CMenu()
{
	position = 1;
}

//Run both before the engine actually runs, and then whenever the gamemode enum is set to Menu
void CMenu::MenuSetup(I3DEngine* myEngine)
{
	screenMesh = myEngine->LoadMesh("quad.x");
	screen = screenMesh->CreateModel(0, 5, -5);
	screen->SetSkin("NewGameScreen.png");
	screen->Scale(8);
	screen->ScaleX(1.7);
	screen->RotateX(90);
	isDead = false;
}

//Due to access issues, Update is essentially a game loop in itself
//Basically it just adjusts the position whenever you press up/W or down/S and navigates through the menu
//uses Enums passed as reference so main game loop can function properly
//depending on where you hit enter, it does different stuff. 
void CMenu::MenuUpdate(I3DEngine* myEngine, gameState& state)
{
	if (position == 1)
	{
		screen->SetSkin("NewGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			position = 2;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			position = 3;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			state = BuildLevel; //Starts a new game
		}
	}
	else if (position == 2)
	{
		screen->SetSkin("ContinueScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			position = 3;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			position = 1;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			position = 1;	//currently just puts the menu back to new game
			//Maybe set a level in here if we can expand in time
		}
	}
	else if (position == 3)
	{
		screen->SetSkin("ExitGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			position = 1;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			position = 2;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->Stop();
		}
	}
}

//Gets rid of the menu model from the screen before starting the game up -> Not called within the main game loop
//it's only called when the player presses enter when on new game. 
void CMenu::CloseDown()
{
	//screen->SetY(-100.0f);
	screenMesh->RemoveModel(screen);
}

CMenu::~CMenu()
{
}
