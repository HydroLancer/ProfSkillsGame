#include "CScenery.h"
CScenery::CScenery(I3DEngine* myEngine)
{
	ifstream infile("Scenery.txt");
	string line;
	x = 0;
	y = 0;
	sceneItemType = 0;
	
	shipMesh = myEngine->LoadMesh("HoverTank04.x");
	tankMesh = myEngine->LoadMesh("HoverTank03.x");
	floorMesh = myEngine->LoadMesh("floor.x");
	//buildingMesh = myEngine->LoadMesh("");

	while (getline(infile, line)) // Reads in the new line from csv file
	{
		x = 0;
		//loops through each character of string and inputs to floor array
		for (int i = 0; i < line.length(); i++)
		{
			sceneItemType = line[i] - '0';//converts characters in .csv file into integer

			//create cube type from above character read
			CreateScenery(sceneItemType, x, y);
			x++;
		}
		y++;
	}
}

void CScenery::CreateScenery(int sceneItem, int x, int y) 
{
	IModel* sceneModel;

	if (sceneItem == 1) 
	{
		sceneModel = shipMesh->CreateModel(x* 5.0f, y* 10.0f, 10.0f);
		sceneModel->RotateY(90.0f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 2)
	{
		sceneModel = tankMesh->CreateModel(x* 5.0f, y*10.0f,  10.0f);
		sceneModel->RotateY(-90.0f);
		SceneList.push_back(sceneModel);
	}
	else if (sceneItem == 3)
	{
		floor = floorMesh->CreateModel(0.0f, -5.0f, 0.0f);
		floor->SetSkin("menu_floor.png");
		floor->Scale(1.0f);
	}
	else
	{

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
