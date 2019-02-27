#include "LoadingMap.h"

LoadingMap::LoadingMap()
{
}

bool LoadingMap::LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[],
 float endCoords[], float& timeLimit, float& mapWidth, float mapHeight, string levelName)
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
					switch (nodeCode[1])
					{
					case 1:
						row.push_back(CoinBlock);
						break;
					case 2:
						row.push_back(SuperMushroomBlock);
						break;
					case 3:
						row.push_back(FireFlowerBlock);
						break;
					case 4:									//As blocks can have items within, set depending on the 2nd number
						row.push_back(BlueShellBlock);		//blocks are usually coded 1[x]0
						break;
					case 5:
						row.push_back(StamanBlock);
						break;
					case 6:
						row.push_back(MegamushroomBlock);
						break;
					case 7:
						row.push_back(MiniMushroomBlock);
						break;
					case 8:
						row.push_back(OneUpBlock);
						break;
					default:
						row.push_back(Block);		//Empty block
						break;
					}
				}
				if (nodeCode[0] == '2')
				{
					row.push_back(Coin);	//... as above
				}
				if (nodeCode[0] == '3') //Block Type. Anything within in what pops out. 0 is an empty one. 
				{
					switch (nodeCode[1])
					{
					case 1:
						row.push_back(CoinItem);
						break;
					case 2:
						row.push_back(SuperMushroomItem);
						break;
					case 3:
						row.push_back(FireFlowerItem);
						break;
					case 4:
						row.push_back(BlueShellItem);
						break;
					case 5:
						row.push_back(StamanItem);
						break;
					case 6:
						row.push_back(MegamushroomItem);
						break;
					case 7:
						row.push_back(MiniMushroomItem);
						break;
					case 8:
						row.push_back(OneUpItem);
						break;
					default:
						row.push_back(Item);		//Just to be safe. Essentially a dummy item block
						break;
					}
				}
				if (nodeCode[0] == '4')
				{
					row.push_back(Ground);
				}
				if (nodeCode[0] == '5')
				{
					switch (nodeCode[2])
					{
					case 1:
						row.push_back(GoombaEnemy);
						break;
					case 2:
						row.push_back(GreenKoopaEnemy);
						break;
					case 3:
						row.push_back(RedKoopaEnemy);
						break;
					case 4:
						row.push_back(DryBonesEnemy);
						break;
					default:
						row.push_back(GoombaEnemy); // Just so if someone forgets to name a specific enemy, default to goomba0
					}

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

bool LoadingMap::LevelBuild(I3DEngine* myEngine, float startCoods[], FullLevel level, float mapWidth, vector<IModel*>& floor, 
							vector<IModel*>& itemBox, vector<IModel*>& coin, vector<IModel*>& enemy, vector<IModel*>& block)
{
	//Passes the engine into this function so that the class can load the meshes and push the models into the vectors that have been
	//defined in main.
	vector<IModel*>::iterator it;
	IMesh* playerMesh = myEngine->LoadMesh("Planet.x");
	IModel* player = playerMesh->CreateModel(startCoods[0], startCoods[1], 0);
	IMesh* floorMesh = myEngine->LoadMesh("Box.x");
	IMesh* itemBoxMesh = myEngine->LoadMesh("Torus.x");
	IMesh* coinMesh = myEngine->LoadMesh("Sphere.x");
	IMesh* enemyMesh = myEngine->LoadMesh("TwoPence.x");
	IMesh* blockMesh = myEngine->LoadMesh("Arrow.x");

	for (int i = 0; i < level.size(); i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (level[i][j] == Ground)
			{
				floor.push_back(floorMesh->CreateModel(j, i, 0));
			}
			if (level[i][j] == Item)
			{
				itemBox.push_back(itemBoxMesh->CreateModel(j, i, 0));
			}
			if (level[i][j] == Coin)
			{
				coin.push_back(coinMesh->CreateModel(j, i, 0));
			}
			if (level[i][j] == GoombaEnemy)
			{
				enemy.push_back(enemyMesh->CreateModel(j, i, 0));
			}
			if (level[i][j] == Block)
			{
				block.push_back(blockMesh->CreateModel(j, i, 0));
			}
		}
	}

	//Once the models are loaded into their corresponding vectors, adjusts the scaling on them to make the level look sane.
	for (auto it = enemy.begin(); it != enemy.end(); ++it)
	{
		(*it)->Scale(0.095);
	}
	for (auto it = block.begin(); it != block.end(); ++it)
	{
		(*it)->Scale(0.1);
	}
	for (auto it = floor.begin(); it != floor.end(); ++it)
	{
		(*it)->Scale(0.1);
	}
	for (auto it = coin.begin(); it != coin.end(); ++it)
	{
		(*it)->Scale(0.1);
	}
	for (auto it = itemBox.begin(); it != itemBox.end(); ++it)
	{
		(*it)->Scale(0.08);
	}
	return true;
}
LoadingMap::~LoadingMap()
{
}
