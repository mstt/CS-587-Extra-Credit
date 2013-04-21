#ifndef __ICONTROLLER_H_
#define __ICONTROLLER_H_

#include "Actor.h"
#include "Point.h"

/*
	IController
	======================
	Controls an actor. Moves randomly
*/
class IController
{
public:
	/* Data */
	//Actor* actor;

	/* Functions */
	//IController(Actor* actor) : actor(actor) {};
	virtual Point GetNextPosition() = 0;
	virtual void MoveTo(int x, int y) = 0;
	//void MoveTo(int x, int y) { actor->x = x; actor->y = y; };
};

#endif