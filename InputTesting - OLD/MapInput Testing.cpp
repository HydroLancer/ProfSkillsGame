// MapInput Testing.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <fstream>
#include <vector>
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	enum BlockType
	{
		Ground = 4,
		Item = 3,
		Coin = 2,
		Block = 1,
		Air = 0
	};

	string currentLevel = "map2.txt";
	ifstream inputfile;
	vector<vector<BlockType>> map;
	vector<vector<BlockType>>::iterator mapit;
	vector<BlockType> row;
	vector<BlockType>::iterator it;

	int single;

	int mapWidth = 0;
	int mapHeight = 9;
	int startCoods[2];
	int endCoords[2];
	int timeLimit;
	int counter = 0;


	inputfile.open(currentLevel);
	int count = 0;
	while (!inputfile.eof())
	{
		if (count == 0)
		{
			inputfile >> mapWidth;
			count++;
		}
		if (count == 1)
		{
			inputfile >> startCoods[0];
			count++;
		}
		if (count == 2)
		{
			inputfile >> startCoods[1];
			count++;
		}
		if (count == 3)
		{
			inputfile >> endCoords[0];
			count++;
		}
		if (count == 4)
		{
			inputfile >> endCoords[1];
			count++;
		}
		if (count == 5)
		{
			inputfile >> timeLimit;
			count++;
			inputfile >> noskipws;
		}
		if (count >= 6)
		{
			while (counter < mapWidth)
			{
				inputfile >> single;
				it = row.begin();
				switch (single)
				{
				case 1:
					row.insert(it, Block);
					break;
				case 2:
					row.insert(it, Coin);
					break;
				case 3:
					row.insert(it, Item);
					break;
				case 4:
					row.insert(it, Ground);
					break;
				case 0:
					row.insert(it, Air);
					break;
				}
				counter++;
			}
			mapit = map.begin();
			map.insert(mapit, row);
			row.clear();
			counter = 0;
			if (map.size() >= mapHeight)
			{
				break;
			}
		}
	}
	inputfile.close();
	I3DEngine* myEngine = New3DEngine(kTLX);
	myEngine->StartWindowed();
	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );

	/**** Set up your scene here ****/
	IMesh* characterMesh = myEngine->LoadMesh("planet.x");
	IMesh* floorMesh = myEngine->LoadMesh("box.x");
	IMesh* boxMesh = myEngine->LoadMesh("Cube.x");



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
