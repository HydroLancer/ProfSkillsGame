#include "CPlayer.h"

// Allow debug-only code
#ifndef __DEBUG
	#define __DEBUG
#endif // !__DEBUG

CPlayer::CPlayer(I3DEngine* myEngine, CGameMap* m)
{
	playerMesh = myEngine->LoadMesh(PLAYER_MODEL);
	player = playerMesh->CreateModel(3.0f, 3.0f, 0.0f);
	player->SetSkin(PLAYER_SKIN);
	player->Scale(0.1f);

	oldX = player->GetX();
	oldY = player->GetY();

	rotation = 0.0f;

	jumpSpeed = 0.0f;
	jumpState = noJump;

	//// COLLISION INITIALISATION ////
	collisionHorizontalBlock = noMSide;	// Blocks
	collisionVerticalBlock = noJSide;

	collsionHorizontalSpike = noMSide;	// Spikes
	collisionVerticalSpike = noJSide;

	collsionHorizontalCoin = noMSide;	// Coins
	collisionVerticalCoin = noJSide;

	numCoins = 0; // Initialise the number of coins a player has to 0
}

void CPlayer::PlayerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collisionBlock, boxMovementSide collisionSpike, boxMovementSide collisionCoin, CGameMap* map) // Controls player movement
{
	collisionBlock = CheckHorizontalBlockCol(myEngine, map); // Check which side the collision is on
	collisionSpike = CheckHorizontalSpikeCol(myEngine, map); // Check which side the collision is on
	collisionCoin = CheckHorizontalCoinCol(myEngine, map); // Check which side the collision is on

	
	if (collisionBlock == leftSide || collisionBlock == rightSide) // Check to see if there is collision on either side of the model
	{
		SetOldX(); // If so, set the 'X' of the model to the previous 'X' position
	}
	
	if (collisionSpike == leftSide || collisionSpike == rightSide) // Check to see if there is collision on either side of the model
	{
		SetOldX(); // If so, set the 'X' of the model to the previous 'X' position
	}

	if (collisionCoin != noMSide)
	{
		numCoins++;
		cout << "COINS: " << numCoins << endl;
	}

	oldX = player->GetX(); // Reset the 'oldX' to the current 'X' position of the model

	// Jumping Mechanic
	if (myEngine->KeyHit(JUMP)) // If the jump key is pressed then
	{
		cout << "JUMP PRESSED" << endl; // TEST::OUTPUT "JUMP PRESSED" TO CONSOLE
		SetOldY();
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
			if (PLAYER_SPEED < 0) // different directions of player spinning
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
#ifdef __DEBUG
	if (myEngine->KeyHeld(LEFT)) // If the left movement key is pressed
	{
		player->MoveX(-PLAYER_SPEED * frameTime); // Move the model negative x
	}
	else if (myEngine->KeyHeld(RIGHT))
	{
		player->MoveX(PLAYER_SPEED * frameTime); // Move the model positive x
	}
#else
	player->MoveX(-PLAYER_SPEED * frameTime); // Move the model negative x
#endif // DEBUG

}

void CPlayer::Update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera) // Updates the scene each frame
{
	PlayerMovement(myEngine, frameTime, collisionHorizontalBlock, collsionHorizontalSpike, collsionHorizontalCoin, map); // Update the player movement
	PlayerJump(myEngine, frameTime, collisionVerticalBlock, collisionVerticalSpike, map); // Update the jump state every frame
	camera->SetX(player->GetX());
}

void CPlayer::PlayerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collisionBlock, boxJumpingSide collisionSpike, CGameMap* map) // Controls player jumping mechanic
{
	collisionBlock = CheckVerticalBlockCol(myEngine, map);
	collisionSpike = CheckVerticalSpikeCol(myEngine, map);
	// Move model according to jump state
	/* Collision Resolution */
	if (collisionBlock == bottomSide || collisionSpike == bottomSide) //bottom of a floor block 
	{
		jumpSpeed = 0.0f; // stop the jumping upwards if we hit the bottom of a block
		SetOldY(); // so we dont clip through the map entity like the floor
	}
	if (collisionBlock == topSide || collisionSpike == topSide) // top of a floor block or whatever map entity
	{
		SetOldY(); // land on top stop the player falling through
		if (jumpState == DoubleJump)
		{
			player->RotateZ(-rotation); // reset cool spin for the player
		}
		if (jumpState != noJump)
		{
			jumpState = noJump; //turn off jumping if we are not pressing it anymore
		}
		jumpSpeed = 0.0f; // remove any left over speed in jump
	}
	else
	{
		jumpSpeed -= GRAVITY; // gravity on all the time

	}
	if (jumpState == DoubleJump)
	{
		player->RotateZ(rotate * frameTime); // do a cool spin for the player
		rotation += rotate * frameTime;
	}

	if (collisionBlock == noJSide || collisionSpike == noJSide)
	{
		oldY = player->GetY(); // keep getting the player oldY as we move in the air so we can get a realistic landing
	}

	player->SetY(player->GetY() + (jumpSpeed * frameTime)); // when we jump how far we can jump
}


//////////////////////////////////////////////////
////										  ////
////	COLLISION DETECTION AND RESOLUTION    ////
////										  ////
//////////////////////////////////////////////////

//// BLOCKS ////
boxMovementSide CPlayer::CheckHorizontalBlockCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel* block in map->blocks) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), 1.0f, 1.0f); // check for collision
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalBlockCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* block in map->blocks)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), 1.0f, 1.0f);
		if (collision != noJSide)
		{
			break;
		}
	}

	return collision;
}

//// SPIKES ////
boxMovementSide CPlayer::CheckHorizontalSpikeCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel* spike in map->spikes) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, spike->GetX(), spike->GetY(), 1.0f, 1.0f); // check for collision
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalSpikeCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* spike in map->spikes)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, spike->GetX(), spike->GetY(), 1.0f, 1.0f);
		if (collision != noJSide)
		{
			break;
		}
	}

	return collision;
}

//// COINS ////
boxMovementSide CPlayer::CheckHorizontalCoinCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel* coin in map->coins) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, coin->GetX(), coin->GetY(), 1.0f, 1.0f); // check for collision
		if (collision != noMSide)
		{
			coin->Move(-100.0f, 0.0f, 0.0f);
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalCoinCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* coin in map->coins)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, coin->GetX(), coin->GetY(), 1.0f, 1.0f);
		if (collision != noJSide)
		{
			break;
		}
	}

	return collision;
}

CPlayer::~CPlayer()
{
}
