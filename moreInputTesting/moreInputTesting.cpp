// moreInputTesting.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <fstream>
#include <vector>
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );

	enum BlockType
	{
		Enemy = 500,
		Ground = 400,
		Item = 300,
		Coin = 200,
		Block = 100,
		Air = 0
	};

	vector<vector<BlockType>> map;
	vector<vector<BlockType>>::iterator mapit;
	vector<BlockType> row;
	vector<BlockType>::iterator it;

	int single;

	int mapWidth = 0;
	int mapHeight = 13;
	int startCoods[2];
	int checkpointCoords[2];
	int endCoords[2];
	int timeLimit;
	int counter = 0;

	int count = 0;

	ifstream levelFile;
	levelFile.open("level1.txt");
	if (!levelFile)
	{
		return;
	}
	while (!levelFile.eof())
	{
		if (count == 0)
		{
			levelFile >> mapWidth;
			levelFile >> startCoods[0];
			levelFile >> startCoods[1];
			levelFile >> checkpointCoords[0];			//This lot takes the first 5 lines from the level file
			levelFile >> checkpointCoords[1];			//sticks them into variables to be used later
			levelFile >> endCoords[0];
			levelFile >> endCoords[1];
			levelFile >> timeLimit;
			count++;
		}
		if (count > 0)
		{
			char nodeCode[3];
			string actualCode;
			levelFile.get();
			while (counter < mapWidth)
			{
				it = row.begin();
				nodeCode[0] = levelFile.get();
				nodeCode[1] = levelFile.get();
				nodeCode[2] = levelFile.get();	//gets a 3 number code from the input file ready for comparisons below

				//For the below, the map uses a 3 digit code to identify objects in a scene. for example, 000 - Air, 302 - Green Koopa
				//So for comparison, just use the first and third 'digit' to identify which exact item needs to be put in.
				//just add more ifs within the main if to differentiate between an item block that releases a mushroom or a coin.
				//below has more explanation and examples anyhoo. Just need an expansion of the enum BlockType above.

				if (nodeCode[0] == '0')
				{
					row.insert(it, Air);	//only air begins with zero, so..
				}
				if (nodeCode[0] == '1')
				{
					row.insert(it, Block);	//block is a 1 type object too. 
				}
				if (nodeCode[0] == '2')
				{
					row.insert(it, Coin);	//... as above
				}
				if (nodeCode[0] == '3')
				{
					//can add more ifs to expand	(See enemy for example on how to expand
					row.insert(it, Item); //Is a placeholder for now. There is no just 'item'
				}
				if (nodeCode[0] == '4')
				{
					row.insert(it, Ground);
				}
				if (nodeCode[0] == '5')
				{
					row.insert(it, Enemy); // << Is a placeholder for now. There is no just 'enemy'
					//add more ifs to expand, for example;
					// if ([nodeCode[3] == 2)
					//	{
					//		row.insert(it, Green Koopa);
					//	}
					
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

	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );

	/**** Set up your scene here ****/


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
