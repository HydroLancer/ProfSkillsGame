#pragma once
#include "ControlHeader.h"
#include "CPlayer.h"

class CPlayer;
class CGameMap
{
private:
	
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

	IMesh* playerMesh;
	IMesh* floorMesh;
	IMesh* coinMesh;
	IMesh* blockMesh;
	IMesh* jumpPadMesh;
	IMesh* spikeMesh;
	IMesh* wheelMesh;

	vector<IModel*>::iterator it;

	//pile o' vectors
	vector<IModel*> floor;
	vector<IModel*> blocks;
	vector<IModel*> coins;
	vector<IModel*> coinReset;
	vector<IModel*> wheels;		//After messing with all this, I realised I can probably just make a single 2D vector with every single model in it.
	vector<IModel*> spikes;	    //--Nathan
	vector<IModel*> jumpPads3;
	vector<IModel*> jumpPads4;
	vector<IModel*> jumpPads5;
	vector<IModel*> jumpPads6;

	IModel* skyBox;

	bool LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[], int& timeLimit, int& mapWidth, float mapHeight, string levelName);
	bool LevelBuild(I3DEngine * myEngine, float startCoods[], FullLevel& level, float mapWidth);
	bool ResetLevel(I3DEngine* myEngine,CPlayer* p);
	void DestroyLevel(I3DEngine * myEngine);
	//// GETTERS ////
	float GetItemWidth() { return GENERIC_WIDTH; } // Returns entity width
	float GetItemHeight() { return GENERIC_HEIGHT; } // Returns entity height

	int GetMapWidth() { return mapWidth; } // Returns the width of the map

	~CGameMap(); // Class Destructor
};

