#include "CHeadsUpDisplay.h"



CHeadsUpDisplay::CHeadsUpDisplay(I3DEngine* thomasTheTLEngine)
{
	debugFont = thomasTheTLEngine->LoadFont("Nova Square", DEBUG_FONT_SIZE); //Nova Square
	coinFont = thomasTheTLEngine->LoadFont("Nova Square", COIN_FONT_SIZE); //Nova Square

	showHUD = false;

	coinMesh = thomasTheTLEngine->LoadMesh("TwoPence.x");
}

void CHeadsUpDisplay::Display(I3DEngine* thomasTheTLEngine, int numCoins, float frameTime, ICamera* myCamera)
{
	if (!showHUD)
	{
		frame = thomasTheTLEngine->CreateSprite(HUD_FRAME_FILE, 0.0f, 0.0f, 0.0f);
	
		coinModel = coinMesh->CreateModel(0.168f, 0.1f, 0.25f);
		coinModel->Scale(0.00065f);

		coinModel->AttachToParent(myCamera);

		showHUD = true;
	}
	else
	{
		coinModel->RotateY(230.0f * frameTime);
		coinFont->Draw(to_string(numCoins), thomasTheTLEngine->GetWidth() - 180, 63, kCyan);
	}
}

void CHeadsUpDisplay::Hide(I3DEngine* thomasTheTLEngine)
{
	if (showHUD)
	{
		coinMesh->RemoveModel(coinModel);

		thomasTheTLEngine->RemoveSprite(frame);

		showHUD = false;
	}
}

void CHeadsUpDisplay::DisplayDebug(int fps, float frameTime, float x, float y, string levelName, int levelLength)
{
	if (showHUD)
	{
		debugFont->Draw("FPS: " + to_string(fps), 45, 40, kCyan);
		debugFont->Draw("FRAME TIME: " + to_string(frameTime), 45, 60, kCyan);
		debugFont->Draw("X: " + to_string(x), 45, 80, kCyan);
		debugFont->Draw("Y: " + to_string(y), 45, 100, kCyan);

		if (levelLength > 0)
		{
			debugFont->Draw("LEVEL NAME: " + levelName, 45, 120, kCyan);
			debugFont->Draw("LEVEL LENGTH: " + to_string(levelLength), 45, 140, kCyan);
		}
	}
}

CHeadsUpDisplay::~CHeadsUpDisplay()
{
}
