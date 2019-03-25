#include "CMenu.h"


CMenu::CMenu()
{
	position = 1;
	menuState = Start;
	spriteDrawn = false;
}

void CMenu::MenuSystem(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
	int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine, gameState& state, ICamera* myCamera)
{
	if (menuState == Start)
	{
		MenuSetup(myEngine);
		menuState = InUse;
	}
	else if (menuState == InUse)
	{
		MenuUpdate(myEngine, state);
	}
	else if (menuState == Loading)
	{
		GameSetup(function, map, startCoods, checkpointCoords, endCoords,
			timeLimit, mapWidth, mapHeight, levelName, myEngine, state);
		menuState = CloseMenu;
	}
	else
	{
		CloseDown(myEngine);
		state = Game;
		myCamera->RotateY(180.0f);
	}
}

//Run both before the engine actually runs, and then whenever the gamemode enum is set to Menu
void CMenu::MenuSetup(I3DEngine* myEngine)
{
	// OLD
	//screenMesh = myEngine->LoadMesh("quad.x");

	//screen = screenMesh->CreateModel(0.0f, 5.0f, -4.5f);
	//screen->SetSkin("NewGameScreen.png");
	//screen->Scale(8);
	//screen->ScaleX(1.7);
	//screen->RotateX(90);

	// NEW
	logo = myEngine->CreateSprite("logo_small.png", ((myEngine->GetWidth() / 2) - 500.0f), 20.0f, 0.0f);

	isDead = false;
	PlayMenuMusic();
}

//These two literally just read the text file, then once that's done, reads the 2D vector constructed by the text file to load the appropriate models. 
void CMenu::GameSetup(CGameMap* level, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
	int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine, gameState& state)
{
	level->LoadTheMap(map, startCoods, checkpointCoords, endCoords, timeLimit, mapWidth, mapHeight, levelName);
	level->LevelBuild(myEngine, startCoods, map, mapWidth);
	PlayLevel1Music();
}

//Due to access issues, Update is essentially a game loop in itself
//Basically it just adjusts the position whenever you press up/W or down/S and navigates through the menu
//uses Enums passed as reference so main game loop can function properly
//depending on where you hit enter, it does different stuff.

void CMenu::MenuUpdate(I3DEngine* myEngine, gameState& state)
{
	if (position == 1)
	{
		if (!spriteDrawn)
		{
			menuSprite = myEngine->CreateSprite("menu1.png", (myEngine->GetWidth() / 2) - 108, (myEngine->GetHeight() / 2) - 110);
			spriteDrawn = true;
		}
		//screen->SetSkin("NewGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 2;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 3;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			menuState = Loading;
		}
	}
	else if (position == 2)
	{
		
		if (!spriteDrawn)
		{
			menuSprite = myEngine->CreateSprite("menu2.png", (myEngine->GetWidth() / 2) - 108, (myEngine->GetHeight() / 2) - 110);
			spriteDrawn = true;
		}
		//screen->SetSkin("ContinueScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 3;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 1;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 1;	//currently just puts the menu back to new game
			//Maybe set a level in here if we can expand in time
		}
	}
	else if (position == 3)
	{
		if (!spriteDrawn)
		{
			menuSprite = myEngine->CreateSprite("menu3.png", (myEngine->GetWidth() / 2) - 108, (myEngine->GetHeight() / 2) - 110);
			spriteDrawn = true;
		}
		//screen->SetSkin("ExitGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 1;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			position = 2;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(menuSprite);
			spriteDrawn = false;
			myEngine->Stop();
		}
	}
	
}

//Gets rid of the menu model from the screen before starting the game up -> Not called within the main game loop
//it's only called when the player presses enter when on new game.
void CMenu::CloseDown(I3DEngine* myEngine)
{
	myEngine->RemoveSprite(logo);
	//screen->SetY(-100.0f);

	//screenMesh->RemoveModel(screen);
}

CMenu::~CMenu()
{
}
