#include "CMap.h"
CMap::CMap(I3DEngine* myEngine)
{
	wallMesh = myEngine->LoadMesh(kWallModel);
	wall = wallMesh->CreateModel(0.0f, 0.0f, 30.0f);
    floorMesh = myEngine->LoadMesh(kFloorModel);
	floor = floorMesh->CreateModel(0.0f, -5.0f, 0.0f);
}
CMap::~CMap() {}
