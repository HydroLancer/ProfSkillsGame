#pragma once
#include "ControlHeader.h"

class CHeadsUpDisplay
{
public:
	CHeadsUpDisplay(I3DEngine* thomasTheTLEngine); // Class Contructor

	//// FUNCTIONS ////
	void Display(I3DEngine* thomasTheTLEngine, int numCoins, float frameTime, ICamera* myCamera);
	void Hide(I3DEngine* thomasTheTLEngine);
	void DisplayDebug(int fps, float frameTime, float x, float y, string levelName, int levelLength);

	~CHeadsUpDisplay(); // Class Destructor

	private:
	//// CONSTANTS ////
	// Integers
	const int DEBUG_FONT_SIZE = 24;
	const int COIN_FONT_SIZE = 80;
	const int NUM_FIELDS = 5;

	// Strings
	const string HUD_FRAME_FILE = "frame.png";

	//// FONTS ////
	IFont* debugFont;
	IFont* coinFont;

	//// SPRITES ////
	ISprite* frame;

	//// MESHES & MODELS ////
	IMesh* coinMesh;
	IModel* coinModel;

	//// BOOLEAN VARIABLES ////
	bool showHUD;
};

