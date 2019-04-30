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
#include "CHeadsUpDisplay.h"

int GetFPS(float frameTime, int& frameCounter, float& secondCounter, int& fps); // Updates the FPS to be displayed

void main()
{
	//// ENUM DECL  ////
	gameState game = MenuScreen;
	EPausedState isPaused = playing;

	//// TL-ENGINE SETUP ////
	I3DEngine* myEngine = New3DEngine( kTLX );	// Create a 3D engine (using TLX engine here) and open a window for it
	myEngine->StartWindowed(1920, 1080);		// Run the engine windowed
	//myEngine->StartFullscreen(1920, 1080);
	myEngine->AddMediaFolder(".\\media");		// Add default folder for meshes and other media

	//// CONSTANTS ////
	// Keys
	const EKeyCode EXIT = Key_Escape;			// Exits the game when hit
	const EKeyCode TOGGLE_HUD = Key_F1;
	const EKeyCode TOGGLE_DEBUG_HUD = Key_F3;

	//// CHARS ////
	char currentLevel = '0';

	// Strings
	string levelName = "level" + to_string(currentLevel) + ".txt";	// File name for the map Test.txt level1.txt

	//// FLOATS ////
	float frameTime = myEngine->Timer(); // Initialise the frame time using the engine's timer
	float secondCounter = 0.0f;
	float secondCounter2 = 0.0f;

	//// INTEGERS ////
	int frameCounter = 0;	// Counts how many frames there are every second
	int fps = 0;			// Allows the number of frames per second to be returned

	//// BOOLEANS ////
	bool showHUD = true;
	bool showDebugHUD = false;
	bool start = false;

	//// SCENE SETUP ////
	CHeadsUpDisplay* HUD = new CHeadsUpDisplay(myEngine);
	CScenery* scenery = new CScenery(myEngine);		// Create a new scenery object
	CGameMap* map = new CGameMap;					// Create a new map loader object
	CPlayer* player = new CPlayer(myEngine, map);	// Create a new player object
	FullLevel level;								// 2D Vector containing positions and types for all models in the level
	CMenu* menu = new CMenu();						// Creates menu class, allows player to start a new game or exit the game (Continue isn't implemented yet)

	ICamera* myCamera = myEngine->CreateCamera(kManual, 0.0f, 5.23f, -12.0f); // Create a camera

	myCamera->RotateY(180.0f);

	// Skybox
	IMesh* skyboxMesh = myEngine->LoadMesh("stars.x");
	IModel* skyBox = skyboxMesh->CreateModel(0, 300.0f, 0);
	skyBox->SetSkin("Background new.png");

	//// SOUNDS ////
	LoadAllSounds(); // Loads all sounds into RAM

	//// MUSIC ////
	//PlayMenuMusic(); // Play the menu music - to be moved when the menu is implemented (Is now in CMenu::MenuSetup [NH])

	//// GAME LOOP ////
	while (myEngine->IsRunning()) // The main game loop, repeat until engine is stopped
	{
		frameTime = myEngine->Timer(); // Update the frame time using the engine's timer

		myEngine->DrawScene(); // Draw the scene

		GetFPS(frameTime, frameCounter, secondCounter, fps); // Get the current FPS

		myEngine->SetWindowCaption(("Shape Sprint (FPS: " + to_string(fps) + ")"));

		/**** Update your scene each frame here ****/

		if (isPaused == playing)
		{
			if (myEngine->KeyHit(Key_P))
			{
				isPaused = paused;
			}

			//// DEBUG HUD ////
			if (showDebugHUD) // Display debug HUD if true
			{
				HUD->DisplayDebug(fps, frameTime, player->GetX(), player->GetY(), levelName, map->GetMapWidth());
			}

			if (myEngine->KeyHit(TOGGLE_DEBUG_HUD)) // Toggle debug HUD
			{
				if (showDebugHUD)
				{
					showDebugHUD = false;
				}
				else
				{
					showDebugHUD = true;
				}
			}

			//Builds the menu screen with nothing over the top of it.
			if (game == MenuScreen)
			{
				menu->MenuSystem(map, level, map->startCoods, map->checkpointCoords, map->endCoords, map->timeLimit, map->mapWidth, map->mapHeight, levelName, myEngine, game, myCamera);
				skyBox->RotateY(100.0f * frameTime);
			}
			else if (game == NextLevel)
			{
				//So the game doesn't go into evil loops.
				if (map->LoadTheMap(level, map->startCoods, map->checkpointCoords, map->endCoords, map->timeLimit, map->mapWidth, map->mapHeight, levelName))
				{
					map->LevelBuild(myEngine, map->startCoods, level, map->mapWidth);
					game = Game;
					PlayLevel1Music();
				}
				else
				{
					currentLevel = '1';
					StopAllMusic();
					HUD->Hide(myEngine);
					menu->SetMenuState(0);
					game = MenuScreen;
				}
			}
			else // Game is on at this point.
			{

				//// GAME HUD ////
				if (showHUD) // Display HUD if true
				{
					HUD->Display(myEngine, player->GetNumCoins(), frameTime, myCamera);
				}
				else
				{
					HUD->Hide(myEngine);
				}

				if (myEngine->KeyHit(TOGGLE_HUD)) // Toggle HUD on or off
				{
					if (showHUD)
					{
						showHUD = false;
					}
					else
					{
						showHUD = true;
					}
				}

				// Move the skybox
				skyBox->RotateY(100.0f * frameTime);
				skyBox->SetY((player->GetY()) * 25.0f);
				skyBox->SetX(player->GetX());

				scenery->UpdateScenery(frameTime);

				// Rotate all coins in the level constantly
				for (auto it = map->coins.begin(); it != map->coins.end(); ++it)
				{
					(*it)->RotateY(230.0f * frameTime);
				}
				for (auto it = map->wheels.begin(); it != map->wheels.end(); ++it)
				{
					(*it)->RotateZ(230.0f * frameTime);
				}
				player->Update(myEngine, frameTime, map, myCamera);

				//// END OF LEVEL ////
				if (player->GetX() >= map->endCoords[0])
				{
					currentLevel++;
					player->ResetPlayerPosition();
					levelName = "level";
					levelName = levelName + currentLevel;
					levelName = levelName + ".txt";
					map->DestroyLevel(myEngine);
					game = NextLevel;
					StopAllMusic();
					PlayTransitionSound();
				}
			}
		}
		else
		{
			if (myEngine->KeyHit(Key_P))
			{
				isPaused = playing;
			}
		}

		if (myEngine->KeyHit(EXIT)) // exits the game
		{
			myEngine->Stop();
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

int GetFPS(float frameTime, int& frameCounter, float& secondCounter, int& fps)
{
	secondCounter += frameTime; // Add frame time to second counter
	frameCounter++; // Increment the frame counter every frame

	if (secondCounter > 1.0f) // If one second has passed
	{
		fps = frameCounter; // Set the fps to how many frames have occured

		secondCounter = 0.0f;	// Reset the one second timer
		frameCounter = 0;		// Reset the frame counter
	}
	return fps; // Return the number of frames per second
}
