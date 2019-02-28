#include "CPlayer.h"
CPlayer::CPlayer(I3DEngine* myEngine) //Constructor
{
	playerMesh = myEngine->LoadMesh(kPlayerModel);
	player = playerMesh->CreateModel(0.0f, 0.0f, 0.0f);
	player->SetSkin(kPlayerSkin);
	oldX = 0.0f;
	oldY = 0.0f;
	currentY = 0.0f;
	jumpState = noJump;
}
void CPlayer::playerMovement(I3DEngine* myEngine, float frameTime,boxSide collision)
{
	if (collision == leftSide) // leave it above the getoldX because magic 
	{
		setoldX();
	}
	else if (collision == rightSide)
	{
		setoldX();
	}
	oldX = player->GetX();
	oldY = player->GetY();
	if (myEngine->KeyHit(kJump))
	{
		if (jumpState == noJump) 
		{
			jumpState = Jump;
			jumpSpeed = jump; // reset the jump after gravity has dimmished it
			cout << "JUMP PRESSED" << endl;
		}
		else if (jumpState == Jump) 
		{
			jumpState = DoubleJump;
			jumpSpeed = jump;
			rotation = 0.0f;
			cout << "JUMP PRESSED" << endl;
		}
	}
	if (myEngine->KeyHeld(kLeft))
	{
		player->MoveX(-playerSpeed * frameTime);
	}
	else if (myEngine->KeyHeld(kRight))
	{
		player->MoveX(playerSpeed * frameTime);
	}

}
void CPlayer::update(I3DEngine* myEngine, float frameTime,CMap* map) // for the main engines while loop
{
	boxSide collision;
	collision = checkCollisions(myEngine, map);
	playerMovement(myEngine, frameTime,collision);
	playerJump(myEngine, frameTime, collision);
	
}

void CPlayer::playerJump(I3DEngine* myEngine, float frameTime,boxSide collision) 
{
	if (jumpState == Jump)
	{
		if (collision == topSide)
		{
			jumpState = noJump;
		}
		else if (collision == bottomSide)
		{
			/*jumpSpeed = 0;*/
		}
		currentY = player->GetY();
		jumpSpeed -= gravity;
		player->SetY(currentY + (jumpSpeed *frameTime));
	}
	else if (jumpState == DoubleJump)
	{
		if (collision == topSide) //
		{ 
			jumpState = noJump;
			player->RotateZ(-rotation); // counter the rotation to reset to its original position
		}
		else if (collision == bottomSide)
		{
			/*jumpSpeed = 0;*/
		}
		rotation += (rotate * frameTime);
		player->RotateZ(rotate * frameTime); // cool spin
		currentY = player->GetY();
		jumpSpeed -= gravity;
		player->SetY(currentY + (jumpSpeed *frameTime)); // same as before
		
	}
	else  // gravity on all the time i disabled this since the floor.x isnt going to be used in the main game and all of the map will some type of block
	{
		//gravity/falling
		//if (collision != topSide) //
		//{ //hit floor (needs to replace)
		//	moving = true;
		//	currentY = player->GetY();
		//	jumpSpeed -= gravity;
		//	player->SetY(currentY + (jumpSpeed *frameTime));
		//}
	}
}


boxSide CPlayer::checkCollisions(I3DEngine* myEngine, CMap* map)
{
	boxSide collision;
	collision = BoxToBox(getX(),getY(),height,width,map->GetX(),map->GetY(),10,10);
	//if (collision != noSide)
	//{
	//	collision = noSide; // seeing what state is on
	//}
	return collision;
}


CPlayer::~CPlayer()//Destructor
{

}