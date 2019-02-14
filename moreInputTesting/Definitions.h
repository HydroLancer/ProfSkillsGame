#pragma once
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <fstream>
#include <vector>


using namespace tle;

enum BlockType
{
	//Enemies
	GoombaEnemy = 500,
	GreenKoopaEnemy = 501,
	RedKoopaEnemy = 502,
	DryBonesEnemy = 503,

	Ground = 400,

	//Items
	Item = 300,
	CoinItem = 310,
	SuperMushroomItem = 320,
	FireFlowerItem = 330,
	BlueShellItem = 340,
	StamanItem = 350,
	MegamushroomItem = 360,
	MiniMushroomItem = 370,
	OneUpItem = 380,

	Coin = 200,

	//Blocks
	Block = 100,
	CoinBlock = 110,
	SuperMushroomBlock = 120,
	FireFlowerBlock = 130,
	BlueShellBlock = 140,
	StamanBlock = 150,
	MegamushroomBlock = 160,
	MiniMushroomBlock = 170,
	OneUpBlock = 180,

	Air = 0
}; //Contains about 5 million enums for all item/enemy types.



using FullLevel = vector<vector<BlockType>>;