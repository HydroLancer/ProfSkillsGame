#include "CHeadsUpDisplay.h"



CHeadsUpDisplay::CHeadsUpDisplay(I3DEngine* thomasTheTLEngine)
{
	novaBlack = thomasTheTLEngine->LoadFont("SegoeUI", FONT_SIZE);
}

void CHeadsUpDisplay::DisplayHUD(int numCoins)
{

}

void CHeadsUpDisplay::DisplayDebugHUD(int fps, int frameTime, float x, float y, string levelName)
{
	novaBlack->Draw("FPS: " + to_string(fps), 0, 0);
	novaBlack->Draw("FRAME TIME: " + to_string(frameTime), 0, 20);
	novaBlack->Draw("PLAYER POSITION: " + to_string(x) + ", " + to_string(y), 0, 40);
	novaBlack->Draw("LEVEL NAME: " + levelName, 0, 60);
	//novaBlack->Draw("LEVEL LENGTH: " + levelLength, 0, 0);
}

CHeadsUpDisplay::~CHeadsUpDisplay()
{
}
