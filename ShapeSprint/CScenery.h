#pragma once
#include "ControlHeader.h"
class CScenery
{
private:
	IMesh* shipMesh;
	IMesh* tankMesh;
	IMesh* buildingMesh;
	vector<IModel*>SceneList;
	int sceneItemType;
	int x, y;
public:
	void CreateScenery(int sceneItem, int x, int y);
	void LoadScenery();
	CScenery(I3DEngine* myEngine);
	~CScenery();
};

