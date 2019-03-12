#pragma once

// Project Includes
#include "ControlHeader.h"
#include "Collisions.h"
#include "CGameMap.h"

class CPlayer // Class for the playable character in the game
{
private:
	// Player
	const string PLAYER_MODEL = "Cube.x";
	const string PLAYER_SKIN = "YellowBall.jpg";

	IMesh* playerMesh;
	IModel* player;

	float oldX;	// Models previous 'X' position

	// Movement
	const EKeyCode LEFT = Key_A; // Move model left
	const EKeyCode RIGHT = Key_D; // Move model right
	const EKeyCode JUMP = Key_Space; // Make model jump

	const float JUMP_RESET = 10.0f;	// Reset the jump speed 100
	const float ROTATE = 240.0f; // Rotates the cube round when double jumping
	const float playerSpeed = 2.0f; // The speed of the player



	float jumpSpeed; // The speed at which the player model jumps
	float rotation;	// How much the cube has been rotated by

	// Collision Controls
	const float HEIGHT = 1.0f; // Height of the model
	const float WIDTH = 1.0f; // Width of the model

	// Gravity Controls
	const float GRAVITY = 0.025f; // How much gravity affects the model
public:
	CPlayer(I3DEngine* myEngine); // Class Constructor

	enum EplayerJump { noJump, Jump, DoubleJump }; // Jump state for the player model

	IModel * GetModel();

	void playerMovement(I3DEngine* myEngine, float frameTime, boxSide collision); // Controls player movement

	void playerJump(I3DEngine* myEngine, float frameTime, boxSide collision); // Controls player jumping mechanic
	void update(I3DEngine* myEngine, float frameTime, CGameMap* map); // Updates the scene each frame
	void setX(float x) { player->SetX(x); }	// Sets the 'X' value of a given model
	void setY(float y) { player->SetY(y); } // Sets the 'Y' value of a given model
	void setOldX() { setX(oldX); } // Sets the previous 'X' value of a given model

	float getX() { return player->GetX(); }	// Returns the 'X' value of a given model
	float getY() { return player->GetY(); } // Returns the 'Y' value of a given model
	float getOldX() { return oldX; } // Returns the previous 'X' value of a given model

	boxSide checkCollisions(I3DEngine* myEngine, CGameMap* map); // Checks for collisions between the player model and other models

	~CPlayer();	// Class destructor
private:
	EplayerJump jumpState; // Jump state object

};

