//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "base.h"
#include "world.h"
#include "render.h"

char aWorld[WORLD_SIZE_X + 1];

void ResetWorld()
{
	for (int i = 0; i <= WORLD_SIZE_X; i++)
	{
		aWorld[i] = '#';
	}
}

void PrintWorld()
{
	ChillSetCursor(0,6);
	for (int i = 0; i <= WORLD_SIZE_X; i++) 
	{
		std::cout << aWorld[i];
	}
    std::cout.flush(); //needed for OSX
}

void InitWorld()
{
	ChillClearScreen();
 	ResetWorld();
	PrintWorld();
}
