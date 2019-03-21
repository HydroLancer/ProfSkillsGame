#pragma once
#include "ControlHeader.h"
class CScenery
{
private:
	//// MESHES ////
	IMesh* shipMesh;
	IMesh* tankMesh;
	IMesh* buildingMesh;
	IMesh* floorMesh;

	//// MODELS ////
	IModel* floor;

	vector<IModel*>SceneList;

	int sceneItemType;
	int x, y;

public:
	CScenery(I3DEngine* myEngine);

	void CreateScenery(int sceneItem, int x, int y);
	void UpdateScenery(float frameTime);

	~CScenery();
};

