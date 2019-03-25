#pragma once
#include "ControlHeader.h"

class CGameMap
{
private:
	enum BlockType
	{
		//coin
		Coin = 600,

		//Wheels
		Wheel1x2 = 500, //1x2
		Wheel2x2 = 501, //2x2
		Wheel3x3 = 502, //3x3
		Wheel5x3 = 503, //5x3

		//floor
		Floor = 400,

		//Jump Pad (Number proceeding it is the height it gives)
		JumpPad3 = 303,
		JumpPad4 = 304,
		JumpPad5 = 305,
		JumpPad6 = 306,

		//Spikes
		Spike1x1 = 200,
		Spike1x2 = 210,
		Spike2x3 = 220,

		//Block
		Block = 100,

		//Air
		Air = 0
	}; 
	//SIZES OF MAP ITEMS
//size of most the items are 1x1 
	const float GENERIC_WIDTH = 1.0f;
	//size of most the items are 1x1 
	const float GENERIC_HEIGHT = 1.0f;
public:
	CGameMap();

	const float mapHeight = 13;

	float startCoods[2];
	float checkpointCoords[2];
	float endCoords[2];
	int timeLimit;
	int mapWidth;

	//pile o' vectors
	vector<IModel*> floor;
	vector<IModel*> blocks;
	vector<IModel*> coins;
	vector<IModel*> wheels;		//After messing with all this, I realised I can probably just make a single 2D vector with every single model in it.
	vector<IModel*> spikes;	    //--Nathan
	vector<IModel*> jumpPads3;
	vector<IModel*> jumpPads4;
	vector<IModel*> jumpPads5;
	vector<IModel*> jumpPads6;

	IModel* skyBox;

	using FullLevel = vector<vector<BlockType>>;

	bool LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[], int& timeLimit, int& mapWidth, float mapHeight, string levelName);
	bool LevelBuild(I3DEngine * myEngine, float startCoods[], FullLevel& level, float mapWidth);
	
	//// GETTERS ////
	float GetItemWidth() { return GENERIC_WIDTH; } // Returns entity width
	float GetItemHeight() { return GENERIC_HEIGHT; } // Returns entity height

	int GetMapWidth() { return mapWidth; } // Returns the width of the map

	~CGameMap(); // Class Destructor
};

