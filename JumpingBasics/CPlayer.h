#pragma once
#include "ControlHeader.h"
#include "CMap.h"
#include "Collisions.h"
class CPlayer
{
private:
	//Player
	IModel* player;
	IMesh* playerMesh;
	const string kPlayerModel = "Cube.x";
	const string kPlayerSkin = "YellowBall.jpg";
	const float kPlayerRadius = 5.0f;
	float oldX, oldZ, oldY;
	//Movement 
	const EKeyCode kLeft = Key_A;
	const EKeyCode kRight = Key_D;
	const EKeyCode kJump = Key_Space;
	float jumpSpeed;
	float jump = 100.0f;
	float rotate = 240.0f;
	float rotation = 0.0f;
	float currentY;
	float playerSpeed = 50.0f;
	const float kChangeJump = 2.0f;
	const float kChangeSpeed = 0.05f;
	//Gravity Controls
	float gravity = 0.025f;
	const float kChangeGrav = 0.1f;
	bool  bJump = false;
	bool moving = false;
	bool landing = false;
public:
	CPlayer(I3DEngine* myEngine);
	void playerMovement(I3DEngine* myEngine, float frameTime, float oldFrameTime);
	void checkCollisions(I3DEngine* myEngine, CMap* map);
	void update(I3DEngine* myEngine, float frameTime, float oldFrameTime, CMap* map);
	float getX() { return player->GetX(); }
	float getY() { return player->GetY(); }
	float getZ() { return player->GetZ(); }
	float getOldX() { return oldX; }
	float getOldY() { return oldY; }
	float getOldZ() { return oldZ; }
	void setX(float x) { player->SetX(x); }
	void setY(float y) { player->SetY(y); }
	void setZ(float z) { player->SetZ(z); }
	void setoldX() { setX(oldX); }
	void setoldY() { setY(oldY); }
	void setoldZ() { setZ(oldZ); }
	enum EplayerJump { noJump, Jump, DoubleJump };
	~CPlayer();
private: 
	EplayerJump jumpState;
};

