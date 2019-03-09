// ShapeSprint.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
#include "ControlHeader.h"
#include "CPlayer.h"
#include "CGameMap.h"
#include "CCamera.h"
#include "Collisions.h"

using namespace tle;

//TO DO
/*
Change the collisions for the map to loop through all the objects
*/

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();
	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );
	myEngine->AddMediaFolder("media");
	/**** Set up your scene here ****/
		// Load the map file in
	CGameMap* map = new CGameMap; // Create a map loader object

	CGameMap::FullLevel level; //2D Vector
	const string levelName = "level1.txt"; // File name for the map
	map->LoadTheMap(level, map->startCoods, map->checkpointCoords, map->endCoords, map->timeLimit, map->mapWidth, map->mapHeight, levelName);

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		/**** Update your scene each frame here ****/


	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
