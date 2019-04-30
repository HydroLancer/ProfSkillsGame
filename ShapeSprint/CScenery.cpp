#include "CScenery.h"
CScenery::CScenery(I3DEngine* myEngine)
{
	ifstream infile("Scenery.txt");
	string line;
	x = 0;
	y = 0;
	sceneItemType = 0;
	
	myEngine->AddMediaFolder(MODEL_DIR);	// Add default folder for meshes and other media

	skyscraper02Mesh = myEngine->LoadMesh("skyscraper02.x");
	floorMesh = myEngine->LoadMesh("floor.x");
    buildingMesh = myEngine->LoadMesh("Building03.x");
	buildingMesh2 = myEngine->LoadMesh("Building09.x");
	buildingMesh3 = myEngine->LoadMesh("Building07.x");

	while (getline(infile, line)) // Reads in the new line from csv file
	{
		x = 0;
		//loops through each character of string and inputs to floor array
		for (int i = 0; i < line.length(); i++)
		{
			sceneItemType = line[i] - '0';//converts characters in .csv file into integer

			//create cube type from above character read
			CreateScenery(sceneItemType, x, y);
			++x;
		}
		++y;
	}
}

void CScenery::CreateScenery(int sceneItem, int x, int y) 
{
	IModel* sceneModel;

	if (sceneItem == 1) 
	{
		sceneModel = skyscraper02Mesh->CreateModel(x* 5.0f, -5.0f, 10.0f);
		sceneModel->Scale(0.15f);
		sceneModel->RotateY(90.0f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 2)
	{
		sceneModel = skyscraper02Mesh->CreateModel(x* 5.0f, -5.0f,  25.0f);
		sceneModel->RotateY(-90.0f);
		sceneModel->Scale(0.15f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 3)
	{
		floor = floorMesh->CreateModel(-1.5f, -5.0f, 0.0f);
		floor->SetSkin(MODEL_DIR + "menu_floor.png");
		floor->Scale(1.0f);
	}
	else if (sceneItem == 4)
	{
		sceneModel = buildingMesh->CreateModel(x* 5.0f, -5.0f, 18.0f);
		sceneModel->Scale(0.15f);
		sceneModel->RotateY(90.0f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 5)
	{
		sceneModel = buildingMesh2->CreateModel(x* 5.0f, -5.0f, 15.0f);
		sceneModel->Scale(0.15f);
		sceneModel->RotateY(90.0f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 6)
	{
		sceneModel = buildingMesh3->CreateModel(x* 5.0f, -5.0f, 18.0f);
		sceneModel->Scale(0.10f);
		sceneModel->RotateY(90.0f);
		SceneList.push_back(sceneModel);
	}
	else
	{
		// do nothing
	}
}

void CScenery::UpdateScenery(float frameTime)
{
	if (floor->GetZ() < 8.25f) //8.25f
	{
		floor->MoveZ(10.0f * frameTime);
	}
	else
	{
		floor->SetZ(0.0f);
	}
}

CScenery::~CScenery()
{
}
