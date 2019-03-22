#pragma once
#include "ControlHeader.h"

class CHeadsUpDisplay
{
public:
	CHeadsUpDisplay(I3DEngine* thomasTheTLEngine); // Class Contructor

	//// FUNCTIONS ////
	void DisplayHUD(int numCoins);
	void DisplayDebugHUD(int fps, int frameTime, float x, float y, string levelName);

	~CHeadsUpDisplay(); // Class Destructor

	private:
	//// ENGINES ////
	
	
	//// CONSTANTS ////
		// Integers
	const int FONT_SIZE = 24;
	const int NUM_FIELDS = 5;

	//// FONTS ////
	IFont* novaBlack;

	//// BOOLEAN VARIABLES ////
	bool showHUD;
	bool showDebugHUD;
};

