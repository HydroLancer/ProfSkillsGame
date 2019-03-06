#include "CCamera.h"

CCamera::CCamera(I3DEngine* myEngine)
{
	myCamera = myEngine->CreateCamera(kManual);
	myCamera->SetPosition(0.0f, 10.0f, -50.0f);
}

CCamera::~CCamera()
{
}
