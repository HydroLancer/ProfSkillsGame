#pragma once
// Project Includes
#include "ControlHeader.h"
#include "Collisions.h"
#include "CGameMap.h"
#include "Sound.h"
class CGameMap;
class CPlayer // Class for the playable character in the game
{
private:
	//// CONSTANTS ////
	const string PLAYER_MODEL = "Cube.x";
	const string PLAYER_SKIN = "playertexture.png";

	// Movement Keys
	const EKeyCode LEFT = Key_A;	 // Move model left
	const EKeyCode RIGHT = Key_D;	 // Move model right
	const EKeyCode JUMP = Key_Space; // Make model jump

	// Movement Multipliers and Resets
	const float JUMP_RESET = 15.0f;	  // Reset the jump speed 
	const float ROTATE = 240.0f;	  // Rotates the cube round when double jumping
	const float PLAYER_SPEED = 9.0f; // The speed of the player
	const float ADJUSTMENT_AMOUNT = 0.8f;

	// Collision Controls
	const float HEIGHT = 0.99f; // Height of the model
	const float WIDTH = 0.99f; // Width of the model
	
	// Gravity Controls
	const float GRAVITY = 45.0f; // How much gravity affects the model 0.025f  0.06f

	//// INTEGER VARIABLES ////
	int numCoins;

	//// BOOLEANS ////
	bool initCollide; // Used to determine if the player has collided with the ground. When true, allow the player to move

	//// FLOATING POINT VARIABLES ////
	float oldX;	// Models previous 'X' position
	float oldY;	// Models previous 'X' position

	float jumpSpeed; // The speed at which the player model jumps
	float jumpSpeedMulti; // multiplier for the jumppad;
	float rotation;	 // How much the cube has been rotated by
	float rotate;	 // move the rotation of the player //

	//// TL-ENGINE MODEL LOADING ////
	IMesh* playerMesh;
	IModel* player;

	boxMovementSide collisionHorizontalBlock;	// For when the player is moving left and right
	boxJumpingSide  collisionVerticalBlock;		// For when the player is jumping
	boxMovementSide collsionHorizontalSpike;
	boxJumpingSide collisionVerticalSpike;
	boxMovementSide collsionHorizontalCoin;
	boxJumpingSide collisionVerticalCoin;
	boxMovementSide collsionHorizontalWheel;
	boxJumpingSide collisionVerticalWheel;
	boxMovementSide collisionHorizontalFloor;	// For when the player is moving left and right
	boxJumpingSide  collisionVerticalFloor;
	boxMovementSide collisionHorizontalPad;
	boxJumpingSide  collisionVerticalPad;

public:
	CPlayer(I3DEngine* myEngine, CGameMap* m); // Class Constructor

	enum EplayerJump { noJump, Jump, DoubleJump}; // Jump state for the player model
	enum EplayerLife {Alive, Dead};
	//// FUNCTIONS ////
	void PlayerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collisionBlock, boxMovementSide collisionSpike, boxMovementSide collisionCoin, 
	boxMovementSide collisionWheel, boxMovementSide collisionFloor, boxMovementSide collisionJumpPad, CGameMap* map); // Controls player movement
	void PlayerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collisionBlock, boxJumpingSide collisionSpike, 
	boxJumpingSide collisionWheel, boxJumpingSide collisionFloor, boxJumpingSide collisionJumpPad, CGameMap* map); // Controls player jumping mechanic
	void Update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera); // Updates the scene each frame
	void SetX(float x) { player->SetX(x); }	// Sets the 'X' value of a given model
	void setY(float y) { player->SetY(y); } // Sets the 'Y' value of a given model
	void SetToOldX() { SetX(oldX); } // Sets the previous 'X' value of a given model
	void SetToOldY() { setY(oldY); }//Sets the previous 'Y' value of a given model  /* + 0.002f*/
	void SetToOldX(float adjustment) { SetX(oldX + adjustment); } // Sets the previous 'X' value of a given model
	void SetToOldY(float adjustment) { setY(oldY + adjustment); }//Sets the previous 'Y' value of a given model  
	float GetX() { return player->GetX(); }	// Returns the 'X' value of a given model
	float GetY() { return player->GetY(); } // Returns the 'Y' value of a given model
	float GetOldX() { return oldX; } // Returns the previous 'X' value of a given model

	int GetNumCoins() { return numCoins; } // Returns the number of coins the player currently has
	void ResetCoins() { numCoins = 0; }
	void ResetPlayerPosition() { player->SetPosition(3.0f, 3.0f, 0.0f); }
	void ResetDeathState() { lifeState = Alive; }
	//PLAYER DEATH
	void PlayerDeath(float frameTime);

	//// COLLISION CHECKING FUNCTIONS////
	boxMovementSide CheckHorizontalBlockCol(I3DEngine* myEngine, CGameMap* map); // Blocks
	boxJumpingSide CheckVerticalBlockCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalSpikeCol(I3DEngine* myEngine, CGameMap* map); // Spikes 
	boxJumpingSide CheckVerticalSpikeCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalCoinCol(I3DEngine* myEngine, CGameMap* map); // Coins 
	boxJumpingSide CheckVerticalCoinCol(I3DEngine* myEngine, CGameMap* map);
	
	boxMovementSide CheckHorizontalWheelCol(I3DEngine* myEngine, CGameMap* map); // Wheel
	boxJumpingSide CheckVerticalWheelCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalFloorCol(I3DEngine* myEngine, CGameMap* map); // Floor Blocks
	boxJumpingSide CheckVerticalFloorCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalPadCol(I3DEngine* myEngine, CGameMap* map); // Jump Pad
	boxJumpingSide CheckVerticalPadCol(I3DEngine* myEngine, CGameMap* map);
	~CPlayer();	// Class destructor
private:
	EplayerJump jumpState; // Jump state object
	EplayerLife lifeState; // life of the player
};

