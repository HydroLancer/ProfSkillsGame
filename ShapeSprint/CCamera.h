#pragma once
#include "ControlHeader.h"

class CCamera
{
private:
	ICamera* myCamera;
public:
	CCamera(I3DEngine* myEngine);
	~CCamera();
};

