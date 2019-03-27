#pragma once

#include <TL-Engine.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <SFML/Audio.hpp>

using namespace tle;

enum gameState {MenuScreen, Idle, BuildLevel, LoadingGame, Game, NextLevel};

enum BlockType
{
	//coin
	Coin = 600,

	//Wheels
	Wheel1x2 = 500, //1x2
	Wheel2x2 = 501, //2x2
	Wheel3x3 = 502, //3x3
	Wheel5x3 = 503, //5x3

	//floor
	Floor = 400,

	//Jump Pad (Number proceeding it is the height it gives)
	JumpPad3 = 303,
	JumpPad4 = 304,
	JumpPad5 = 305,
	JumpPad6 = 306,

	//Spikes
	Spike1x1 = 200,
	Spike1x2 = 210,
	Spike2x3 = 220,

	//Block
	Block = 100,

	//Air
	Air = 0
};
using FullLevel = vector<vector<BlockType>>;