#pragma once

// Project Includes
#include "ControlHeader.h"
#include "Collisions.h"
#include "CGameMap.h"
#include "Sound.h"
class CPlayer // Class for the playable character in the game
{
private:
	// Player
	const string PLAYER_MODEL = "Cube.x";
	const string PLAYER_SKIN = "playertexture.png";

	IMesh* playerMesh;
	IModel* player;

	float oldX;	// Models previous 'X' position
	float oldY;	// Models previous 'X' position
	// Movement
	const EKeyCode LEFT = Key_A; // Move model left
	const EKeyCode RIGHT = Key_D; // Move model right
	const EKeyCode JUMP = Key_Space; // Make model jump

	const float JUMP_RESET = 15.0f;	// Reset the jump speed 
	const float ROTATE = 240.0f; // Rotates the cube round when double jumping
	const float playerSpeed = 18.0f; // The speed of the player
	boxMovementSide collisionHorizontalBlock; // for when the player is moving left and right
	boxJumpingSide  collisionVerticalBlock; // for when the player is jumping
	boxMovementSide collsionHorizontalSpike;
	boxJumpingSide collisionVerticalSpike;
	float jumpSpeed; // The speed at which the player model jumps
	float rotation;	// How much the cube has been rotated by

	// Collision Controls
	const float HEIGHT = 0.99f; // Height of the model
	const float WIDTH = 0.99f; // Width of the model
	float rotate;
	// Gravity Controls
	const float GRAVITY = 0.025f; // How much gravity affects the model
public:
	CPlayer(I3DEngine* myEngine, CGameMap* m); // Class Constructor

	enum EplayerJump { noJump, Jump, DoubleJump, preJump }; // Jump state for the player model
	void PlayerMovement(I3DEngine* myEngine, float frameTime, boxMovementSide collisionBlock, boxMovementSide collisionSpike, CGameMap* map); // Controls player movement
	void PlayerJump(I3DEngine* myEngine, float frameTime, boxJumpingSide collisionBlock, boxJumpingSide collisionSpike, CGameMap* map); // Controls player jumping mechanic
	void Update(I3DEngine* myEngine, float frameTime, CGameMap* map, ICamera* camera); // Updates the scene each frame
	void SetX(float x) { player->SetX(x); }	// Sets the 'X' value of a given model
	void setY(float y) { player->SetY(y); } // Sets the 'Y' value of a given model
	void SetOldX() { SetX(oldX); } // Sets the previous 'X' value of a given model
	void SetOldY() { setY(oldY); }
	float GetX() { return player->GetX(); }	// Returns the 'X' value of a given model
	float GetY() { return player->GetY(); } // Returns the 'Y' value of a given model
	float GetOldX() { return oldX; } // Returns the previous 'X' value of a given model

	/////COLLISION CHECKING FUNCTIONS//////
	boxMovementSide CheckHorizontalBlockCol(I3DEngine* myEngine, CGameMap* map); // blocks
	boxJumpingSide CheckVerticalBlockCol(I3DEngine* myEngine, CGameMap* map);
	boxMovementSide CheckHorizontalSpikeCol(I3DEngine* myEngine, CGameMap* map); // spikes 
	boxJumpingSide CheckVerticalSpikeCol(I3DEngine* myEngine, CGameMap* map);
	~CPlayer();	// Class destructor
private:
	EplayerJump jumpState; // Jump state object
};

