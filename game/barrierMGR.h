/*========================================================
	Ran out of time disregard code.
==========================================================*/
#pragma once
#include "Barrier.h"
#include <list>
using namespace std;

class BarrierMGR
{
//data 
private:
	list<Barrier*> barrierList;
	Texture barrier1, barrier2, barrier3, barrier4, barrier5, barrier6, barrier7, barrier8, barrier9, barrier10, barrier11, barrier12, barrier13, barrier14, barrier15;
public:
// functions
private:
	void initializeBarriers();
public:
	BarrierMGR();
	Texture* getTexture(int textNum);
};