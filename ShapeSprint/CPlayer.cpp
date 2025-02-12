#include "CPlayer.h"

CPlayer::CPlayer(I3DEngine* myEngine, CGameMap* m)
{
	initCollide = false;
	
	playerMesh = myEngine->LoadMesh(PLAYER_MODEL);
	player = playerMesh->CreateModel(3.0f, 3.0f, 0.0f); //3.0f
	player->SetSkin(PLAYER_SKIN);
	player->Scale(0.1f);

	oldX = player->GetX();
	oldY = player->GetY();

	rotation = 0.0f;

	jumpSpeed = 0.0f;
	jumpSpeedMulti = 20.0f;
	jumpState = noJump;

	//// COLLISION INITIALISATION ////
	collisionHorizontalBlock = noMSide;	// Blocks
	collisionVerticalBlock = noJSide;

	collsionHorizontalSpike = noMSide;	// Spikes
	collisionVerticalSpike = noJSide;

	collsionHorizontalCoin = noMSide;	// Coins
	collisionVerticalCoin = noJSide;

	collsionHorizontalWheel = noMSide; // Wheels
	collisionVerticalWheel = noJSide;

	collisionHorizontalFloor = noMSide; //Floor Block
	collisionVerticalFloor = noJSide;

	collisionHorizontalPad = noMSide; //Floor Block
	collisionVerticalPad = noJSide;

	numCoins = 0; // Initialise the number of coins a player has to 0

	lifeState = Alive;
}
void CPlayer::PlayerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collisionBlock, boxMovementSide collisionSpike, boxMovementSide collisionCoin, 
	boxMovementSide collisionWheel, boxMovementSide collisionFloor, boxMovementSide collisionJumpPad, CGameMap* map) // Controls player movement
{
	if (lifeState != Dead)
	{
		collisionBlock = CheckHorizontalBlockCol(myEngine, map); // Check which side the collision is on
		collisionSpike = CheckHorizontalSpikeCol(myEngine, map); // Check which side the collision is on
		collisionCoin = CheckHorizontalCoinCol(myEngine, map); // Check which side the collision is on
		collisionWheel = CheckHorizontalWheelCol(myEngine, map);
		collisionFloor = CheckHorizontalFloorCol(myEngine, map);
		collisionJumpPad = CheckHorizontalPadCol(myEngine, map);
		if (collisionBlock == topSide)
		{
			player->SetY(static_cast<int>(player->GetY()) + 0.5f);
		}
		if (collisionBlock == leftSide /*|| collisionBlock == rightSide*/) // Check to see if there is collision on either side of the model
		{
			lifeState = Dead;
		}
		if (collisionFloor == leftSide || collisionFloor == rightSide) // Check to see if there is collision on either side of the model
		{
			SetToOldX(); // If so, set the 'X' of the model to the previous 'X' position
		}
		if (collisionSpike == leftSide || collisionSpike == rightSide || collisionSpike == topMSide) // Check to see if there is collision on either side of the model
		{
			lifeState = Dead;
		}
		if (collisionWheel == leftSide || collisionWheel == rightSide || collisionSpike == topMSide)
		{
			lifeState = Dead;
		}
		if (player->GetY() < -4.0f)
		{
			lifeState = Dead;
		}
		if (collisionJumpPad == leftSide || collisionJumpPad == rightSide || collisionJumpPad == topMSide)
		{
			jumpSpeed + jumpSpeedMulti;
		}
		if (collisionCoin != noMSide)
		{
			numCoins++;
		}

		oldX = player->GetX(); // Reset the 'oldX' to the current 'X' position of the model

		// Jumping Mechanic
		if (myEngine->KeyHit(JUMP)) // If the jump key is pressed then
		{
			SetToOldY(ADJUSTMENT_AMOUNT * frameTime);

			if (jumpState == noJump) // If the model is not currently jumping
			{
				jumpState = Jump; // Set the jump state to 'Jump'
				jumpSpeed = JUMP_RESET; // Reset the jump after gravity has dimmished it
				PlayJumpSound();
			}
			else if (jumpState == Jump) // If the model is currently jumping
			{
				jumpState = DoubleJump; // Set the jump state to 'DoubleJump'
				jumpSpeed = JUMP_RESET; // Reset the jump after gravity has diminished it
				PlayJumpSound();
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
		player->MoveX(PLAYER_SPEED * frameTime); // Move the model negative x
	}
}

void CPlayer::Update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera) // Updates the scene each frame
{
	PlayerJump(myEngine, frameTime, collisionVerticalBlock, collisionVerticalSpike, collisionVerticalWheel, collisionVerticalFloor, collisionVerticalPad, map); // Update the jump state every frame

	if (initCollide)
	{
		PlayerMovement(myEngine, frameTime, collisionHorizontalBlock, collsionHorizontalSpike, collsionHorizontalCoin, collsionHorizontalWheel, collisionHorizontalFloor, collisionHorizontalPad, map); // Update the player movement
	}

	camera->SetX(player->GetX());
	if (lifeState == Dead)
	{
		PlayerDeath(frameTime);
		map->ResetLevel(myEngine,this);
	}
}

void CPlayer::PlayerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collisionBlock, boxJumpingSide collisionSpike, 
	boxJumpingSide collisionWheel, boxJumpingSide collisionFloor, boxJumpingSide collisionJumpPad, CGameMap* map) // Controls player jumping mechanic
{
	if (lifeState != Dead)
	{
		collisionBlock = CheckVerticalBlockCol(myEngine, map);
		collisionSpike = CheckVerticalSpikeCol(myEngine, map);
		collisionWheel = CheckVerticalWheelCol(myEngine, map);
		collisionFloor = CheckVerticalFloorCol(myEngine, map);

		
		// Move model according to jump state
		////////////////////////////////
		////						////
		////  COLLISION RESOLUTION  ////
		////						////
		////////////////////////////////
		// Blocks and floor
		if (collisionBlock == bottomSide || collisionFloor == bottomSide) //bottom of a floor block 
		{
			jumpSpeed = 0.0f; // stop the jumping upwards if we hit the bottom of a block
			SetToOldY(-ADJUSTMENT_AMOUNT * frameTime); // so we dont clip through the map entity like the floor
		}
		if (collisionBlock == topSide || collisionFloor == topSide) // top of a floor block or whatever map entity
		{
			if (!initCollide)
			{
				initCollide = true;
			}

			//SetToOldY(ADJUSTMENT_AMOUNT * frameTime); // land on top stop the player falling through

			player->SetY(static_cast<int>(player->GetY()) + 1.0f);

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
			jumpSpeed -= GRAVITY * frameTime; // gravity on all the time
		}
		if (jumpState == DoubleJump)
		{
			player->RotateZ(rotate * frameTime); // do a cool spin for the player
			rotation += rotate * frameTime;
		}


		if (collisionBlock == noJSide || collisionSpike == noJSide || collisionWheel == noJSide || collisionFloor == noJSide)
		{
			oldY = player->GetY(); // keep getting the player oldY as we move in the air so we can get a realistic landing
		}
		player->SetY(player->GetY() + (jumpSpeed *frameTime)); // when we jump how far we can jump
	}
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
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
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
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, block->GetX(), block->GetY(), map->GetItemHeight(), map->GetItemWidth());
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
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, spike->GetX(), spike->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
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
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, spike->GetX(), spike->GetY(), map->GetItemHeight(), map->GetItemWidth());
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
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, coin->GetX(), coin->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
		if (collision != noMSide)
		{
			PlayCoinPickupSound();
			coin->Move(0.0f, -100.0f, 0.0f);
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
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, coin->GetX(), coin->GetY(), map->GetItemHeight(), map->GetItemWidth());
		if (collision != noJSide)
		{
			PlayCoinPickupSound();
			coin->Move(0.0f, -100.0f, 0.0f);
			break;
		}
	}

	return collision;
}

//// WHEELS ////
boxMovementSide CPlayer::CheckHorizontalWheelCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel* wheel in map->wheels) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, wheel->GetX(), wheel->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalWheelCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* wheel in map->wheels)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, wheel->GetX(), wheel->GetY(), map->GetItemHeight(), map->GetItemWidth());
		if (collision != noJSide)
		{
			break;
		}
	}

	return collision;
}

//// FLOOR ////
boxMovementSide CPlayer::CheckHorizontalFloorCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel* fl in map->floor) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, fl->GetX(), fl->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalFloorCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* fl in map->floor)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, fl->GetX(), fl->GetY(), map->GetItemHeight(), map->GetItemWidth());
		if (collision != noJSide)
		{
			break;
		}
	}
	return collision;
}
boxMovementSide CPlayer::CheckHorizontalPadCol(I3DEngine* myEngine, CGameMap* map)
{
	boxMovementSide collision = noMSide;
	for each(IModel*pad in map->jumpPads3) // go through each block in the map
	{
		collision = HorizontalCollision(GetX(), GetY(), HEIGHT, WIDTH, pad->GetX(), pad->GetY(), map->GetItemHeight(), map->GetItemWidth()); // check for collision
		if (collision != noMSide)
		{
			break;
		}
	}
	return collision;
}
boxJumpingSide CPlayer::CheckVerticalPadCol(I3DEngine* myEngine, CGameMap* map)
{
	boxJumpingSide collision = noJSide;
	for each(IModel* pad in map->jumpPads3)
	{
		collision = VerticalCollision(GetX(), GetY(), HEIGHT, WIDTH, pad->GetX(), pad->GetY(), map->GetItemHeight(), map->GetItemWidth());
		if (collision != noJSide)
		{
			break;
		}
	}
	return collision;
}



//PLAYER DEATH ANIMATION
void CPlayer::PlayerDeath(float frameTime)
{
	PlayDeathSound();
	RestartMusic();
}
CPlayer::~CPlayer()
{
}
