/*========================================================
	Ran out of time disregard code.
==========================================================*/
#include "barrierMGR.h"

#pragma once

void BarrierMGR::initializeBarriers()
{
	for (int i = 0; i < 5; i++)
	{

	}
}

BarrierMGR::BarrierMGR()
{
	if (!barrier1.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier3.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier3.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier4.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier5.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier6.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier7.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier8.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier9.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier10.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier11.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier12.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier13.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier14.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
	if (!barrier15.loadFromFile("barrier_1.png"))
	{
		exit(EXIT_FAILURE);
	}
}

Texture* BarrierMGR::getTexture(int textNum)
{
	Texture* textPtr;

	if (textNum == 1)
	{
		textPtr = &barrier1;
	}
	else if (textNum == 2)
	{
	textPtr = &barrier2;
	}
	else if (textNum == 3)
	{
		textPtr = &barrier3;
	}
	else if (textNum == 4)
	{
		textPtr = &barrier4;
	}
	else if (textNum == 5)
	{
		textPtr = &barrier5;
	}
	else if (textNum == 6)
	{
		textPtr = &barrier6;
	}
	else if (textNum == 7)
	{
		textPtr = &barrier7;
	}
	else if (textNum == 8)
	{
		textPtr = &barrier8;
	}
	else if (textNum == 9)
	{
		textPtr = &barrier9;
	}
	else if (textNum == 10)
	{
		textPtr = &barrier10;
	}
	else if (textNum == 11)
	{
		textPtr = &barrier11;
	}
	else if (textNum == 12)
	{
		textPtr = &barrier12;
	}
	else if (textNum == 13)
	{
		textPtr = &barrier13;
	}
	else if (textNum == 14)
	{
		textPtr = &barrier14;
	}
	else
	{
		textPtr = &barrier15;
	}

	return textPtr;
}
