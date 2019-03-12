#include "CGameMap.h"



CGameMap::CGameMap()
{
}

// NEEDS COMMENTING //
bool CGameMap::LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[], float& timeLimit, float& mapWidth, float mapHeight, string levelName)
{
	ifstream levelFile; //input file - Should be variations of level[x].txt

	vector<BlockType> row;
	vector<BlockType>::iterator it;
	vector<vector<BlockType>>::iterator mapit;

	int counter = 0;
	int count = 0;

	levelFile.open(levelName); //change this for a parameter passed from main, usually set at the end of a level
	if (!levelFile)
	{
		return false;
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
			char nodeCode[3];		//As the way the file is read in, reads 3 ints into this array for comparison below.
			levelFile.get();		//Gets 1 char - This one is to skip the carriage return.
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
					row.push_back(Air);	//only air begins with zero, so..
				}

				if (nodeCode[0] == '1')
				{
					row.push_back(Block); //No fancy blocks this time.
				}

				if (nodeCode[0] == '2')
				{
					switch (nodeCode[1])
					{
					case '0':
						row.push_back(Spike1x1);
						break;
					case '1':
						row.push_back(Spike1x2);		
						break;							//Middle numbers in the 3 digit code refer to spike type
					case '2':								//So the switch checks the 2nd digit and acts accordingly
						row.push_back(Spike2x3);		
						break;
					
					}
				}
				if (nodeCode[0] == '3') 
				{
					switch (nodeCode[2])
					{
					case '3':
						row.push_back(JumpPad3);
						break;
					case '4':
						row.push_back(JumpPad4);
						break;
					case '5':								
						row.push_back(JumpPad5);
						break;
					case '6':
						row.push_back(JumpPad6);
						break;
					}
				}
				if (nodeCode[0] == '4')
				{
					row.push_back(Floor);
				}
				if (nodeCode[0] == '5')
				{
					switch (nodeCode[2])
					{
					case '0':
						row.push_back(Wheel1x2);
						break;
					case '1':
						row.push_back(Wheel2x2);
						break;
					case '2':
						row.push_back(Wheel3x3);
						break;
					case '3':
						row.push_back(Wheel5x3);
						break;
					}				
				}
				if (nodeCode[0] == '6')
				{
					row.push_back(Coin);
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
	return true;
}

/*Goes through the 2D Vector looking at each node in the vector and pushes a new model pointer into a vector of type Model pointer. (It has the position too because
the 2d vector essentially functions as a grid.) then in the game engine, the game actually places each model.*/ 
bool CGameMap::LevelBuild(I3DEngine* myEngine, float startCoods[], FullLevel& level, float mapWidth) 
{
	/*Passes the engine into this function so that the class can load the meshes and push the models into the vectors that have been
	defined in main.*/

	vector<IModel*>::iterator it;
	IMesh* playerMesh = myEngine->LoadMesh("Planet.x");
	IModel* player = playerMesh->CreateModel(startCoods[0], startCoods[1], 0.0f);
	IMesh* floorMesh = myEngine->LoadMesh("Cube.x");
	IMesh* coinMesh = myEngine->LoadMesh("Sphere.x");
	IMesh* blockMesh = myEngine->LoadMesh("Cube.x");
	IMesh* jumpPadMesh = myEngine->LoadMesh("Arrow.x");
	IMesh* spikeMesh = myEngine->LoadMesh("Teapot.x");
	IMesh* wheelMesh = myEngine->LoadMesh("Torus.x");

	/*This essentially goes through the 2d vector formed by loading the text file, and makes the level appear on screen by loading
	all the models needed for the level's layout into vectors of their types*/
	for (int i = 0; i < level.size(); i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (level[i][j] == Floor)
			{
				floor.push_back(floorMesh->CreateModel(j, i, 0.0f));
			}
			if (level[i][j] == Coin)
			{
				coins.push_back(coinMesh->CreateModel(j, i, 0.0f));
			}

			/*These are all the jumpPad vectors. So many.  All do the same thing, so condensed them down to be less overwhelming.
			Splitting them up purely because each pad gives you different height jumps. Stuff like spikes and wheels all do the same thing when you hit them (as far as I'm aware)
			so fine detail isn't too urgent with them*/
			if (level[i][j] == JumpPad3)
			{
				jumpPads3.push_back(jumpPadMesh->CreateModel(j, i, 0.0f));
				//Set Skin?
			}
			if (level[i][j] == JumpPad4)
			{
				jumpPads4.push_back(jumpPadMesh->CreateModel(j, i, 0.0f));
				//Set Skin?
			}
			if (level[i][j] == JumpPad5)
			{
				jumpPads5.push_back(jumpPadMesh->CreateModel(j, i, 0.0f));
				//Set Skin?
			}
			if (level[i][j] == JumpPad6)
			{
				jumpPads6.push_back(jumpPadMesh->CreateModel(j, i, 0.0f));
				//Set Skin?
			}
			
			if (level[i][j] == Block)
			{
				blocks.push_back(blockMesh->CreateModel(j, i, 0.0f));
			}

			//kind of the same with spikes, except they all go in the same vector, but resized beforehand. 
			if (level[i][j] == Spike1x1)
			{
				IModel* spike = spikeMesh->CreateModel(j, i, 0.0f);
				spike->Scale(0.5f);
				spikes.push_back(spike);
			}
			if (level[i][j] == Spike1x2)
			{
				IModel* spikyBoye = spikeMesh->CreateModel(j, i, 0.0f);
				spikyBoye->Scale(0.7f);
				spikes.push_back(spikyBoye);
			}
			if (level[i][j] == Spike2x3)
			{
				IModel* spikyBoye = spikeMesh->CreateModel(j, i, 0.0f);
				spikyBoye->Scale(1.3f);
				spikes.push_back(spikyBoye);
			}

			//...and wheels. 
			if (level[i][j] == Wheel1x2)
			{
				IModel* wheel = wheelMesh->CreateModel(j, i, 0.0f);
				wheel->RotateLocalX(90.0f);
				wheel->Scale(0.05f);
				wheels.push_back(wheel);
			}
			if (level[i][j] == Wheel2x2)
			{
				IModel* wheel = wheelMesh->CreateModel(j, i, 0.0f);
				wheel->Scale(0.1f);
				wheel->RotateLocalX(90.0f);
				wheels.push_back(wheel);
			}
			if (level[i][j] == Wheel3x3)
			{
				IModel* wheel = wheelMesh->CreateModel(j, i, 0.0f);
				wheel->Scale(0.2f);
				wheel->RotateLocalX(90.0f);
				wheels.push_back(wheel);
			}
			if (level[i][j] == Wheel5x3)
			{
				IModel* wheel = wheelMesh->CreateModel(j, i, 0.0f);
				wheel->Scale(0.35f);
				wheel->RotateLocalX(90.0f);
				wheels.push_back(wheel);
			}
		}
	}

	//Once the models are loaded into their corresponding vectors, adjusts the scaling on them to make the level look sane.
	
	for (auto it = blocks.begin(); it != blocks.end(); ++it)
	{
		(*it)->Scale(0.1f);
	}
	for (auto it = floor.begin(); it != floor.end(); ++it)
	{
		(*it)->Scale(0.1f);
	}
	for (auto it = coins.begin(); it != coins.end(); ++it)
	{
		(*it)->Scale(0.1f);
	}
	return true;
}

float CGameMap::GetX(IModel* model)
{
	return model->GetX();
}

float CGameMap::GetY(IModel* model)
{
	return model->GetY();
}

float CGameMap::GetZ(IModel* model)
{
	return model->GetZ();
}

CGameMap::~CGameMap()
{
}
