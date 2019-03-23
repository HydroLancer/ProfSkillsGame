#include "CHeadsUpDisplay.h"



CHeadsUpDisplay::CHeadsUpDisplay(I3DEngine* thomasTheTLEngine)
{
	debugFont = thomasTheTLEngine->LoadFont("Nova Square", DEBUG_FONT_SIZE); //Nova Square
	coinFont = thomasTheTLEngine->LoadFont("Nova Square", COIN_FONT_SIZE); //Nova Square

	frameShown = false;
	coinLoaded = false;

	coinMesh = thomasTheTLEngine->LoadMesh("TwoPence.x");
}

void CHeadsUpDisplay::DisplayHUD(I3DEngine* thomasTheTLEngine, int numCoins, float frameTime, ICamera* myCamera)
{
	if (!frameShown)
	{
		frame = thomasTheTLEngine->CreateSprite(HUD_FRAME_FILE, 0.0f, 0.0f, 0.0f);
		frameShown = true;
	}

	if (coinLoaded == false)
	{
		coinModel = coinMesh->CreateModel(0.17f, 0.1f, 0.25f);
		coinModel->Scale(0.0007f);

		coinModel->AttachToParent(myCamera);

		coinLoaded = true;
	}
	else
	{
		coinModel->RotateY(230.0f * frameTime);
		coinFont->Draw(to_string(numCoins), thomasTheTLEngine->GetWidth() - 180, 63, kCyan);
	}
}

void CHeadsUpDisplay::HideHUD(I3DEngine* thomasTheTLEngine)
{
	coinMesh->RemoveModel(coinModel);
	thomasTheTLEngine->RemoveSprite(frame);
	coinLoaded = false;
	frameShown = false;
}

void CHeadsUpDisplay::DisplayDebugHUD(int fps, float frameTime, float x, float y, string levelName, int levelLength)
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

CHeadsUpDisplay::~CHeadsUpDisplay()
{
}
