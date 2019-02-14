#pragma once
#include "Definitions.h"
class LoadingMap
{
public:
	LoadingMap();
	bool LoadTheMap(FullLevel& map, float startCoods[], float checkpointCoords[], float endCoords[], float& timeLimit, float& mapWidth, float mapHeight);
	bool LevelBuild(I3DEngine* myEngine, float startCoods[], FullLevel level, float mapWidth, vector<IModel*>& floor, vector<IModel*>& itemBox, vector<IModel*>& coin, vector<IModel*>& enemy, vector<IModel*>& block);
	~LoadingMap();
};

