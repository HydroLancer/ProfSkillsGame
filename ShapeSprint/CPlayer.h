#pragma once


// Project Includes
#include "ControlHeader.h"
#include "Collisions.h"
#include "CGameMap.h"
#include "Sound.h"
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
	const float PLAYER_SPEED = 18.0f; // The speed of the player

	// Collision Controls
	const float HEIGHT = 0.99f; // Height of the model
	const float WIDTH = 0.99f; // Width of the model
	

	// Gravity Controls
	const float GRAVITY = 0.05f; // How much gravity affects the model 0.025f

	//// INTEGER VARIABLES ////
	int numCoins;

	//// FLOATING POINT VARIABLES ////
	float oldX;	// Models previous 'X' position
	float oldY;	// Models previous 'X' position

	float jumpSpeed; // The speed at which the player model jumps
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
public:
	CPlayer(I3DEngine* myEngine, CGameMap* m); // Class Constructor

	enum EplayerJump { noJump, Jump, DoubleJump}; // Jump state for the player model
	enum EplayerLife {Alive, Dead};
	//// FUNCTIONS ////
	void CPlayer::PlayerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collisionBlock, boxMovementSide collisionSpike, boxMovementSide collisionCoin, 
		boxMovementSide collisionWheel, CGameMap* map); // Controls player movement
	void PlayerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collisionBlock, boxJumpingSide collisionSpike, 
		boxJumpingSide collisionWheel, CGameMap* map); // Controls player jumping mechanic
	void Update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera); // Updates the scene each frame
	void SetX(float x) { player->SetX(x); }	// Sets the 'X' value of a given model
	void setY(float y) { player->SetY(y); } // Sets the 'Y' value of a given model
	void SetOldX() { SetX(oldX); } // Sets the previous 'X' value of a given model
	void SetOldY() { setY(oldY); }
	
	float GetX() { return player->GetX(); }	// Returns the 'X' value of a given model
	float GetY() { return player->GetY(); } // Returns the 'Y' value of a given model
	float GetOldX() { return oldX; } // Returns the previous 'X' value of a given model

	//// COLLISION CHECKING FUNCTIONS////
	boxMovementSide CheckHorizontalBlockCol(I3DEngine* myEngine, CGameMap* map); // Blocks
	boxJumpingSide CheckVerticalBlockCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalSpikeCol(I3DEngine* myEngine, CGameMap* map); // Spikes 
	boxJumpingSide CheckVerticalSpikeCol(I3DEngine* myEngine, CGameMap* map);

	boxMovementSide CheckHorizontalCoinCol(I3DEngine* myEngine, CGameMap* map); // Coins 
	boxJumpingSide CheckVerticalCoinCol(I3DEngine* myEngine, CGameMap* map);
	
	boxMovementSide CheckHorizontalWheelCol(I3DEngine* myEngine, CGameMap* map); // Wheel
	boxJumpingSide CheckVerticalWheelCol(I3DEngine* myEngine, CGameMap* map);
	~CPlayer();	// Class destructor
private:
	EplayerJump jumpState; // Jump state object
	EplayerLife lifeState; // life of the player
};

