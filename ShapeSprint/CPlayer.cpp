#include "CPlayer.h"

CPlayer::CPlayer(I3DEngine* myEngine, CGameMap* m)
{
	playerMesh = myEngine->LoadMesh(PLAYER_MODEL);
	player = playerMesh->CreateModel(0, 1.0f, 0.0f);
	player->SetSkin(PLAYER_SKIN);
	player->Scale(0.1f);
	oldX = 0.0f;
	rotation = 0.0f;
	jumpSpeed = 0.0f;
	jumpState = noJump;
}

//getter
IModel* CPlayer::GetModel()
{
	return player;
}

void CPlayer::playerMovement(I3DEngine* myEngine, float frameTime, boxSide collision, CGameMap* map) // Controls player movement
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

void CPlayer::update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera) // Updates the scene each frame
{
	boxSide collision = noSide; // Box side object
	
	collision = checkCollisions(myEngine, map); // Check which side the collision is on
	playerMovement(myEngine, frameTime, collision, map); // Update the player movement
	
	collision = checkCollisions(myEngine, map); // Check which side the collision is on
	playerJump(myEngine, frameTime, collision, map); // Update the jump state every frame

	camera->SetX(player->GetX());
	camera->SetY(player->GetY());
}

// NEEDS COMMENTING //
void CPlayer::playerJump(I3DEngine* myEngine, float frameTime, boxSide collision, CGameMap* map) // Controls player jumping mechanic
{
	/* Collision Resolution */
	if (collision == topSide)
	{
		if (jumpState != noJump)
		{
		jumpState = noJump;
		jumpSpeed = 0.0f;
		}

		/*player->RotateZ(-rotation); */// counter the rotation to reset to its original position
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
		/*rotation += (ROTATE * frameTime);*/
		/*player->RotateZ(ROTATE * frameTime);*/ // cool spin
		jumpSpeed -= GRAVITY;
		player->SetY(player->GetY() + (jumpSpeed *frameTime)); // same as before

	}
	else // gravity on all the time i disabled this since the floor.x isnt going to be used in the main game and all of the map will be some type of block
	{
		/*gravity/falling*/
		if (collision != topSide) //
		{ //hit floor (needs to replace)
			jumpSpeed -= GRAVITY;
			player->SetY(player->GetY() + (jumpSpeed * frameTime));
		}
	}
}

// NEEDS COMMENTING //
boxSide CPlayer::checkCollisions(I3DEngine* myEngine, CGameMap* map)
{
	boxSide collision;

	for each(IModel* flooring in map->floor)
	{
		collision = BoxToBox(getX(), getY(), HEIGHT, WIDTH, flooring->GetX(), flooring->GetY(), 1.0f, 1.0f);
	}
	
	/*for each(IModel* block in map->blocks)
	{
		collision = BoxToBox(getX(), getY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), 1.0f, 1.0f);
	}*/

	return collision; // What i think is happening its fine for the first jump but its going through the list passing back some topside the rest noSide so thats why it falls through
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