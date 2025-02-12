#pragma once
#include "ControlHeader.h"
class CScenery
{
private:
	//// MESHES ////
	IMesh* skyscraper02Mesh;
	IMesh* tankMesh;
	IMesh* buildingMesh;
	IMesh* buildingMesh2;
	IMesh* buildingMesh3;
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

