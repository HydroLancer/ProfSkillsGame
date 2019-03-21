// ShapeSprint.cpp: A program using the TL-Engine

//// INCLUDES ////
#include <string>

//// ENGINE INCLUDES ////
#include <TL-Engine.h>	// TL-Engine include file and namespace

//// PROJECT INCLUDES ////
#include "ControlHeader.h"
#include "CPlayer.h"
#include "CGameMap.h"
#include "CScenery.h"
#include "Collisions.h"
#include "Sound.h"
#include "CMenu.h"

//// FUNCTIONS ////
void UpdateDebugHUD(I3DEngine* myEngine, int fps); // Updates the debug HUD every frame with current statistics

int GetFPS(float frameTime, int& frameCounter, float& secondCounter, int& fps); // Updates the FPS to be displayed

void main()
{
	//// ENUM DECL  ////
	gameState game = MenuScreen;

	//// TL-ENGINE SETUP ////
	I3DEngine* myEngine = New3DEngine( kTLX );	// Create a 3D engine (using TLX engine here) and open a window for it
	myEngine->StartWindowed(1920, 1080);					// Run the engine windowed
	myEngine->AddMediaFolder("media");			// Add default folder for meshes and other media
	
	//// CONSTANTS ////
	const EKeyCode EXIT = Key_Escape;			// Exits the game when hit
	const string levelName = "ShapeTest.txt";	// File name for the map

	//// FLOATS ////
	float frameTime = myEngine->Timer(); // Initialise the frame time using the engine's timer
	int frameCounter = 0;
	float secondCounter = 0.0f;

	//// INTEGERS ////
	int fps = 0;
												
	//// SCENE SETUP ////	
	CScenery* scenery = new CScenery(myEngine);		// Create a new scenery object
	CGameMap* map = new CGameMap;					// Create a new map loader object
	CPlayer* player = new CPlayer(myEngine, map);	// Create a new player object
	CGameMap::FullLevel level;						// 2D Vector containing positions and types for all models in the level
	CMenu* menu = new CMenu;						// Creates menu class, allows player to start a new game or exit the game (Continue isn't implemented yet)

	ICamera* myCamera = myEngine->CreateCamera(kManual, 0, 5.0f, -12.0f); // Create a camera
	
	//// MUSIC ////
	playMenuSound(); // Play the menu music - to be moved when the menu is implemented

	//// GAME LOOP ////
	while (myEngine->IsRunning()) // The main game loop, repeat until engine is stopped
	{
		frameTime = myEngine->Timer(); // Update the frame time using the engine's timer
		
		myEngine->DrawScene(); // Draw the scene

		GetFPS(frameTime, frameCounter, secondCounter, fps); // Get the current FPS

		myEngine->SetWindowCaption(("Shape Sprint (FPS: " + to_string(fps) + ")"));

		/**** Update your scene each frame here ****/
		
		//Builds the menu screen with nothing over the top of it.
		if (game == MenuScreen)
		{
			menu->MenuSetup(myEngine);
			game = Idle;

		}
		//Purely because having it in one function caused errors. Could maybe have this as a mid-game pause too.
		else if (game == Idle)
		{
			menu->MenuUpdate(myEngine, game);
		}
		//if player hits New Game, does this. 
		else if (game == BuildLevel)
		{
			menu->CloseDown();
			map->LoadTheMap(level, map->startCoods, map->checkpointCoords, map->endCoords, map->timeLimit, map->mapWidth, map->mapHeight, levelName); // Load the map file into the map object
			map->LevelBuild(myEngine, map->startCoods, level, map->mapWidth); // Build the level using the loaded map
			game = Game;
		}
		else // if (game == Game) -> Game is basically on at this point. 
		{
			player->Update(myEngine, frameTime, map, myCamera);

			// Move the skybox
			map->skyBox->RotateY(100.0f * frameTime);
			map->skyBox->SetY((player->GetY()) * 25.0f);

			//UpdateDebugHUD(myEngine, fps); // GAME BREAKING

			// Rotate all coins in the level constantly
			for (auto it = map->coins.begin(); it != map->coins.end(); ++it)
			{
				(*it)->RotateY(230.0f * frameTime);
			}

			if (myEngine->KeyHit(EXIT)) // exits the game
			{
				myEngine->Stop();
			}
		}

		
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

void UpdateDebugHUD(I3DEngine* myEngine, int fps)
{
	//// CONSTANTS ////
	const int VERTICAL_SPACING = 10;
	const int FONT_SIZE = 24;
	
	const int NUM_LINES = 5;

	const string DEBUG_INFO[NUM_LINES] = { "FPS", "Player X", "Player Y", "Level Name", "Level Length" };

	IFont* arial = myEngine->LoadFont("Arial", FONT_SIZE); // The font to be used on the heads-up-display for debug stats
	
	arial->Draw((DEBUG_INFO[0] + ": " + to_string(fps)), 0, 0);
}

int GetFPS(float frameTime, int& frameCounter, float& secondCounter, int& fps)
{
	secondCounter += frameTime; // Add frame time to second counter
	frameCounter++; // Increment the frame counter

	if (secondCounter > 1.0f)
	{
		fps = frameCounter;

		secondCounter = 0.0f;
		frameCounter = 0;
	}
	return fps;
}