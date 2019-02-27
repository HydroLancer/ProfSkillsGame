// moreInputTesting.cpp: A program using the TL-Engine

#include "Definitions.h"
#include "LoadingMap.h"

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine(kTLX);
	LoadingMap* MapLoad = new LoadingMap;

	float startCoods[2];
	float checkpointCoords[2];
	float endCoords[2];
	float timeLimit;
	float mapWidth;
	float mapHeight = 13;

	FullLevel level;  //2D Vector
	string levelName = "level1.txt";
	MapLoad->LoadTheMap(level, startCoods, checkpointCoords, endCoords, timeLimit, mapWidth, mapHeight, levelName );
	
	vector<IModel*> floor;
	vector<IModel*> itemBox;
	vector<IModel*> coin;
	vector<IModel*> enemy;
	vector<IModel*> block;

	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder("C:\\ProgramData\\TL-Engine\\Media");

	/**** Set up your scene here ****/
	ICamera* myCamera = myEngine->CreateCamera(kFPS, 0, 0, -15);

	//actually builds the level
	MapLoad->LevelBuild(myEngine, startCoods, level, mapWidth, floor, itemBox, coin, enemy, block);

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		/**** Update your scene each frame here ****/

	}

	// Delete the 3D engine now we are finished with it
	delete MapLoad;
	myEngine->Delete();
}
