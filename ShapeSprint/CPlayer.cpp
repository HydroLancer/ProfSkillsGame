#include "CPlayer.h"

CPlayer::CPlayer(I3DEngine* myEngine)
{
	playerMesh = myEngine->LoadMesh(PLAYER_MODEL);
	player = playerMesh->CreateModel(0.0f, 2.0f, 0.0f);
	player->SetSkin(PLAYER_SKIN);
	player->Scale(0.1f);
	oldX = 0.0f;
	
	jumpState = noJump;
}

//getter
IModel* CPlayer::GetModel()
{
	return player;
}

void CPlayer::playerMovement(I3DEngine* myEngine, float frameTime, boxSide collision) // Controls player movement
{
	if (collision == leftSide || collision == rightSide) // Check to see if there is collision on either side of the model
	{
		setOldX(); // If so, set the 'X' of the model to the previous 'X' position
	}

	oldX = player->GetX(); // Reset the 'oldX' to the current 'X' position of the model

	// Jumping Mechanic
	if (myEngine->KeyHit(JUMP)) // If the jump key is pressed then
	{
		cout << "JUMP PRESSED" << endl; // TEST::OUTPUT "JUMP PRESSED" TO CONSOLE

		if (jumpState == noJump) // If the model is not currently jumping
		{
			jumpState = Jump; // Set the jump state to 'Jump'
			jumpSpeed = JUMP_RESET; // Reset the jump after gravity has dimmished it
		}
		else if (jumpState == Jump) // If the model is currently jumping
		{
			jumpState = DoubleJump; // Set the jump state to 'DoubleJump'
			jumpSpeed = JUMP_RESET; // Reset the jump after gravity has diminished it
			rotation = 0.0f; // Reset the jump amount to 0
		}
	}

	// Movement Mechanic
	if (myEngine->KeyHeld(LEFT)) // If the left movement key is pressed
	{
		player->MoveX(-playerSpeed * frameTime); // Move the model negative x
	}
	else if (myEngine->KeyHeld(RIGHT))
	{
		player->MoveX(playerSpeed * frameTime); // Move the model positive x
	}
}

void CPlayer::update(I3DEngine* myEngine, float frameTime, CGameMap* map) // Updates the scene each frame
{
	boxSide collision; // Box side object
	collision = checkCollisions(myEngine, map); // Check which side the collision is on
	playerMovement(myEngine, frameTime, collision); // Update the player movement
	playerJump(myEngine, frameTime, collision); // Update the jump state every frame
}

// NEEDS COMMENTING //
void CPlayer::playerJump(I3DEngine* myEngine, float frameTime, boxSide collision) // Controls player jumping mechanic
{
	/* Check for collision*/
	if (collision == topSide)
	{
		jumpState = noJump;
		player->RotateZ(-rotation); // counter the rotation to reset to its original position
	}
	else if (collision == bottomSide)
	{
		jumpSpeed = 0.0f;
	}

	// Move model according to jump state
	if (jumpState == Jump)
	{
		jumpSpeed -= GRAVITY;
		player->SetY(player->GetY() + (jumpSpeed *frameTime));
	}
	else if (jumpState == DoubleJump)
	{
		rotation += (ROTATE * frameTime);
		player->RotateZ(ROTATE * frameTime); // cool spin
		jumpSpeed -= GRAVITY;
		player->SetY(player->GetY() + (jumpSpeed *frameTime)); // same as before

	}
	//else // gravity on all the time i disabled this since the floor.x isnt going to be used in the main game and all of the map will be some type of block
	//{
	//	/*gravity/falling*/
	//	if (collision != topSide) //
	//	{ //hit floor (needs to replace)
	//		jumpSpeed -= GRAVITY;
	//		player->SetY(player->GetY() + (jumpSpeed *frameTime));
	//	}
	//}
}

// NEEDS COMMENTING //
boxSide CPlayer::checkCollisions(I3DEngine* myEngine, CGameMap* map)
{
	boxSide collision;
	for (auto floor : map->floor)
	{
		collision = BoxToBox(getX(), getY(), HEIGHT, WIDTH, map->GetX(floor), map->GetY(floor), HEIGHT, WIDTH);
	}
	//if (collision != noSide)
	//{
	//	collision = noSide; // seeing what state is on
	//}
	return collision;
}

CPlayer::~CPlayer()
{
}
/*void Map::Update(I3DEngine* myEngine, Character* c, list<Enemy*> elist, Bullet* b) // CODE THAT WILL HOPEFULLY SAVE US
{
	CheckCollisions(c, b);
	for each(Enemy* e in elist)
	{
		CheckEnemyCollision(e);
	}
}

void Map::CheckCollisions(Character* c, Bullet* b)
{
	boxSide collision;
	for each (IModel* cube in wallcubes)
	{
		collision = sphereToBox(c->getX(), c->getZ(), c->getCharacterRadius(), c->getoldX(), c->getoldZ(), cube->GetX(), cube->GetZ(), getWallLength(), getWallWidth());
		if (collision == frontSide || collision == backSide)
		{
			c->setoldZ();
		}
		else if (collision == leftSide || collision == rightSide)
		{
			c->setoldX();
		}
	} */