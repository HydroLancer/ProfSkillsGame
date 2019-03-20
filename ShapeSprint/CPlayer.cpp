#include "CPlayer.h"

CPlayer::CPlayer(I3DEngine* myEngine, CGameMap* m)
{
	playerMesh = myEngine->LoadMesh(PLAYER_MODEL);
	player = playerMesh->CreateModel(3.0f, 3.0f, 0.0f);
	player->SetSkin(PLAYER_SKIN);
	player->Scale(0.1f);
	oldX =player->GetX();
	oldY = player->GetY();
	rotation = 0.0f;
	jumpSpeed = 0.0f;
	jumpState = noJump;
	collisionMovement = noMSide;
	collisionJumping = noJSide;
}

void CPlayer::playerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collision, CGameMap* map) // Controls player movement
{
	collision = checkMovementCollisions(myEngine, map); // Check which side the collision is on
	if (collision == leftSide || collision == rightSide) // Check to see if there is collision on either side of the model
	{
		setOldX(); // If so, set the 'X' of the model to the previous 'X' position
	}

	oldX = player->GetX(); // Reset the 'oldX' to the current 'X' position of the model

	// Jumping Mechanic
	if (myEngine->KeyHit(JUMP)) // If the jump key is pressed then
	{
		cout << "JUMP PRESSED" << endl; // TEST::OUTPUT "JUMP PRESSED" TO CONSOLE
		setOldY();
		if (jumpState == noJump) // If the model is not currently jumping
		{
			jumpState = Jump; // Set the jump state to 'Jump'
			jumpSpeed = JUMP_RESET; // Reset the jump after gravity has dimmished it
			playJumpSound();
		}
		else if (jumpState == Jump) // If the model is currently jumping
		{
			jumpState = DoubleJump; // Set the jump state to 'DoubleJump'
			jumpSpeed = JUMP_RESET; // Reset the jump after gravity has diminished it
			playJumpSound();
			if (playerSpeed < 0) // different directions of player spinning
			{
				rotate = -ROTATE;
			}
			else 
			{
				rotate = ROTATE;
			}
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
	playerMovement(myEngine, frameTime, collisionMovement, map); // Update the player movement
	playerJump(myEngine, frameTime, collisionJumping, map); // Update the jump state every frame
	camera->SetX(player->GetX());
	//camera->SetY(player->GetY());
}

// NEEDS COMMENTING //
void CPlayer::playerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collision, CGameMap* map) // Controls player jumping mechanic
{
	collision = checkJumpingCollisions(myEngine, map);
	// Move model according to jump state
	/* Collision Resolution */
	if (collision == bottomSide)
	{
		jumpSpeed = 0.0f;
		setOldY();
	}
	if (collision == topSide)
	{
		setOldY();
		if (jumpState == DoubleJump)
		{
			player->RotateZ(-rotation);
		}
		if (jumpState != noJump)
		{
			jumpState = noJump;
		}
		jumpSpeed = 0.0f;

		 // counter the rotation to reset to its original position
	}
	else 
	{
		jumpSpeed -= GRAVITY;
	
	}
	if (jumpState == DoubleJump) 
	{
		player->RotateZ(rotate * frameTime);
		rotation += rotate * frameTime;
	}

	if (collision == noJSide) 
	{
		oldY = player->GetY();
	}

	player->SetY(player->GetY() + (jumpSpeed * frameTime));
}

// NEEDS COMMENTING //
boxMovementSide CPlayer::checkMovementCollisions(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision;

	for each(IModel* flooring in map->floor)
	{
		collision = movementCollision(getX(), getY(), HEIGHT, WIDTH, flooring->GetX(), flooring->GetY(), 1.0f, 1.0f);
		if (collision != noMSide) 
		{
			break;
		}
	}
	for each(IModel* block in map->blocks)
	{
		collision = movementCollision(getX(), getY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), 1.0f, 1.0f);
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision; // What i think is happening its fine for the first jump but its going through the list passing back some topside the rest noSide so thats why it falls through
}
boxJumpingSide CPlayer::checkJumpingCollisions(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision;

	for each(IModel* flooring in map->floor)
	{
		collision = jumpingCollision(getX(), getY(), HEIGHT, WIDTH, flooring->GetX(), flooring->GetY(), 1.0f, 1.0f);
		if (collision != noJSide)
		{
			break;
		}
	}
	for each(IModel* block in map->blocks)
	{
		collision = jumpingCollision(getX(), getY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), 1.0f, 1.0f);
		if (collision != noJSide)
		{
			break;
		}
	}

	return collision; // What i think is happening its fine for the first jump but its going through the list passing back some topside the rest noSide so thats why it falls through
}
CPlayer::~CPlayer()
{
}
