#pragma once
#include "ControlHeader.h"
#include <SFML/Audio.hpp>
float Timer();

//// OPTIMISATIONS ////
void LoadAllSounds();

//// MUSIC ////
void PlayMenuMusic();

// Level Music
void PlayLevel1Music();

//// SFX ////
void PlayJumpSound();
void PlayCoinPickupSound();
