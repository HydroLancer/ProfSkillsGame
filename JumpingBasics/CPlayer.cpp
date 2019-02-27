#include "CPlayer.h"
CPlayer::CPlayer(I3DEngine* myEngine) //Constructor
{
	playerMesh = myEngine->LoadMesh(kPlayerModel);
	player = playerMesh->CreateModel(0.0f, 0.0f, 0.0f);
	player->SetSkin(kPlayerSkin);
	oldX = 0.0f;
	oldY = 0.0f;
	oldZ = 0.0f;
	currentY = 0.0f;
	jumpState = noJump;
}
void CPlayer::playerMovement(I3DEngine* myEngine, float frameTime,float oldFrameTime)
{
	oldX = player->GetX();
	oldZ = player->GetZ();
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
		player->MoveLocalZ(-playerSpeed * frameTime);
		moving = true;
	}
	else if (myEngine->KeyHeld(kRight))
	{
		player->MoveLocalZ(playerSpeed * frameTime);
		moving = true;
	}
	else
	{
		moving = false;
	}
}
void CPlayer::update(I3DEngine* myEngine, float frameTime, float oldFrameTime, CMap* map) // for the main engines while loop
{
	playerMovement(myEngine, frameTime, oldFrameTime);
	checkCollisions(myEngine, map);
	if (jumpState == Jump)
	{
		currentY = player->GetY();
		jumpSpeed -= gravity;
		player->SetY(currentY + (jumpSpeed *frameTime));
		if (player->GetY() < 0.0f) 
		{
			jumpState = noJump;
			player->SetY(0.0f);
		}
	}
	else if(jumpState == DoubleJump)
	{
		rotation += (rotate * frameTime);
		player->RotateX(rotate * frameTime); // cool spin
		currentY = player->GetY();
		jumpSpeed -= gravity;
		player->SetY(currentY + (jumpSpeed *frameTime)); // same as before

		if (player->GetY() < 0.0f) 
		{ //hit floor (needs to replace)
			jumpState = noJump;
			player->SetY(0.0f);
			player->RotateX(-rotation); // counter the rotation to reset to its original position
		}
	}
}

void CPlayer::checkCollisions(I3DEngine* myEngine, CMap* map)
{
	boxSide collision;
	collision = sphereToBox(player->GetX(), player->GetZ(), kPlayerRadius, oldX, oldZ, map->GetX(), map->GetZ(), map->GetLength(), map->GetWidth());
	/*noCollisions = noCollision(playerObj->getX(), playerObj->getZ(), playerObj->getRadius(), playerObj->getOldX(), playerObj->getOldZ(), wall->GetX(), wall->GetZ(), getWallLength(), getWallWidth());*/
	if (landing == false)
	{
		if (collision == frontSide || collision == backSide)
		{
			setoldZ();
		}
	}
	if (jumpState == Jump && moving == true || jumpState == DoubleJump && moving == true)
	{
		if (collision == frontSide || collision == backSide)
		{
			landing = true;
			player->SetY(map->GetY() + 10);
			jumpState = noJump;
		}
	}


}


CPlayer::~CPlayer()//Destructor
{

}