#include "CMenu.h"


CMenu::CMenu()
{
	position = 1;
	menuState = Start;
}

void CMenu::MenuSystem(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
	int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine, gameState& state)
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
			timeLimit, mapWidth, mapHeight, levelName, myEngine);
		menuState = CloseMenu;
	}
	else
	{
		CloseDown(myEngine);
		state = Game;
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

void CMenu::GameSetup(CGameMap* function, FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[],
	int timeLimit, int mapWidth, float mapHeight, string levelName, I3DEngine* myEngine)
{
	function->LoadTheMap(map, startCoods, checkpointCoords, endCoords, timeLimit, mapWidth, mapHeight, levelName);
	function->LevelBuild(myEngine, startCoods, map, mapWidth);
}

//Due to access issues, Update is essentially a game loop in itself
//Basically it just adjusts the position whenever you press up/W or down/S and navigates through the menu
//uses Enums passed as reference so main game loop can function properly
//depending on where you hit enter, it does different stuff.

void CMenu::MenuUpdate(I3DEngine* myEngine, gameState& state)
{

	DrawAllSprites(myEngine);

	if (position == 1)
	{
		myEngine->RemoveSprite(play.flat);
		myEngine->RemoveSprite(levels.hover);
		myEngine->RemoveSprite(exit.hover);

		//screen->SetSkin("NewGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(play.hover);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.flat);
			position = 2;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(play.hover);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.flat);
			position = 3;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(play.hover);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.flat);
			state = BuildLevel; //Starts a new game
		}
	}
	else if (position == 2)
	{
		myEngine->RemoveSprite(play.hover);
		myEngine->RemoveSprite(levels.flat);
		myEngine->RemoveSprite(exit.hover);

		//screen->SetSkin("ContinueScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.hover);
			myEngine->RemoveSprite(exit.flat);
			position = 3;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.hover);
			myEngine->RemoveSprite(exit.flat);
			position = 1;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.hover);
			myEngine->RemoveSprite(exit.flat);
			position = 1;	//currently just puts the menu back to new game
			//Maybe set a level in here if we can expand in time
		}
	}
	else if (position == 3)
	{
		myEngine->RemoveSprite(play.hover);
		myEngine->RemoveSprite(levels.hover);
		myEngine->RemoveSprite(exit.flat);

		//screen->SetSkin("ExitGameScreen.png");
		if (myEngine->KeyHit(Key_S) || myEngine->KeyHit(Key_Down))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.hover);
			position = 1;
		}
		if (myEngine->KeyHit(Key_W) || myEngine->KeyHit(Key_Up))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.hover);
			position = 2;
		}
		if (myEngine->KeyHit(Key_Return))
		{
			myEngine->RemoveSprite(play.flat);
			myEngine->RemoveSprite(levels.flat);
			myEngine->RemoveSprite(exit.hover);
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

void CMenu::DrawAllSprites(I3DEngine* myEngine)
{
	play.hover = myEngine->CreateSprite("new_game_hover.png", 380.0f, 500.0f, 0.0f);
	play.flat = myEngine->CreateSprite("new_game_flat.png", 380.0f, 500.0f, 0.0f);

	levels.hover = myEngine->CreateSprite("continue_game_hover.png", 500.0f, 500.0f, 0.0f);
	levels.flat = myEngine->CreateSprite("continue_game_flat.png", 500.0f, 500.0f, 0.0f);

	exit.flat = myEngine->CreateSprite("exit_flat.png", 500.0f, 680.0f, 0.0f);
	exit.hover = myEngine->CreateSprite("exit_hover.png", 500.0f, 680.0f, 0.0f);
}

CMenu::~CMenu()
{
}
