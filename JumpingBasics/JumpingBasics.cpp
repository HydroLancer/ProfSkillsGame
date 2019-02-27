// JumpingBasics.cpp: A program using the TL-Engine
#include "ControlHeader.h"
#include "CPlayer.h"
#include "CMap.h"
#include "Collisions.h"
void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );
	myEngine->AddMediaFolder("media");
	/**** Set up your scene here ****/
	ICamera* myCamera;
	myCamera = myEngine->CreateCamera(kFPS);
	myCamera->SetPosition(-70.0f, 10.0f, 10.0f);
	myCamera->RotateY(90.0f);
	const EKeyCode kExit = Key_Escape;
	float frameTime = myEngine->Timer();
	float oldFrameTime = frameTime;
	//
	CPlayer* playerObj = new CPlayer(myEngine);
	CMap* mapObj = new CMap(myEngine);
	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		oldFrameTime = frameTime;
		/**** Update your scene each frame here ****/
		playerObj->update(myEngine, frameTime, oldFrameTime, mapObj);
		/*playerObj->playerJumping(myEngine, frameTime, oldFrameTime);*/
		if (myEngine->KeyHit(kExit))
		{
			myEngine->Stop();
		}
		frameTime = myEngine->Timer();
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
