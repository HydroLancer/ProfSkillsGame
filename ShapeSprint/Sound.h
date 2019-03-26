#pragma once
#include "ControlHeader.h"
float Timer();

//// OPTIMISATIONS ////
void LoadAllSounds();

//// MUSIC ////
void PlayMenuMusic();

void RestartMusic();

// Level Music
void PlayLevel1Music();

//// SFX ////
void PlayJumpSound();
void PlayCoinPickupSound();
void PlayDeathSound();