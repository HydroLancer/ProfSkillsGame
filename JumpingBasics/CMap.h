#pragma once
#include "ControlHeader.h"
#include "Collisions.h"
class CMap
{
private:
	IModel* floor;
	IMesh* floorMesh;
	IModel* wall;
	IMesh* wallMesh;
	const string kFloorModel = "Floor.x";
	const string kWallModel = "Cube.x";
	const float kWallWidth = 10.0f;
	const float kWallLength = 10.0f;
public:
	CMap(I3DEngine* myEngine);
	float getWallWidth() { return kWallWidth; }
	float getWallLength() { return kWallLength; }
	float GetX() { return wall->GetX(); }
	float GetY() { return wall->GetY(); }
	float GetZ() { return wall->GetZ(); }
	float GetWidth() { return kWallWidth; }
	float GetLength() { return kWallLength; }
	~CMap();
};

