#pragma once
#include "ControlHeader.h"

class CGameMap
{
private:
	enum BlockType
	{
		//Enemies
		GoombaEnemy = 500,
		GreenKoopaEnemy = 501,
		RedKoopaEnemy = 502,
		DryBonesEnemy = 503,

		Ground = 400,

		//Items
		Item = 300,
		CoinItem = 310,
		SuperMushroomItem = 320,
		FireFlowerItem = 330,
		BlueShellItem = 340,
		StamanItem = 350,
		MegamushroomItem = 360,
		MiniMushroomItem = 370,
		OneUpItem = 380,

		Coin = 200,

		//Blocks
		Block = 100,
		CoinBlock = 110,
		SuperMushroomBlock = 120,
		FireFlowerBlock = 130,
		BlueShellBlock = 140,
		StamanBlock = 150,
		MegamushroomBlock = 160,
		MiniMushroomBlock = 170,
		OneUpBlock = 180,

		Air = 0
	}; //Contains about 5 million enums for all item/enemy types.

public:
	CGameMap();

	const float mapHeight = 13;

	float startCoods[2];
	float checkpointCoords[2];
	float endCoords[2];
	float timeLimit;
	float mapWidth;

	using FullLevel = vector<vector<BlockType>>;

	bool LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[], float& timeLimit, float& mapWidth, float mapHeight, string levelName);
	bool LevelBuild(I3DEngine* myEngine, float startCoods[], FullLevel level, float mapWidth, vector<IModel*>& floor, vector<IModel*>& itemBox, vector<IModel*>& coin, vector<IModel*>& enemy, vector<IModel*>& block);

	float GetX(IModel* model);
	float GetY(IModel* model);
	float GetZ(IModel* model);

	~CGameMap();
};

