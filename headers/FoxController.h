#ifndef __FOX_CONTROLLER_H_
#define __FOX_CONTROLLER_H_

#include "IController.h"
#include "Actor.h"
#include "Point.h"

/*
	FoxController
	======================
	Controls an actor.
*/
class FoxController : public IController
{
public:
	/* Data */
	Actor* actor;

	/* Functions */
	FoxController(Actor* actor) : actor(actor) { }
	Point GetNextPosition();
	void MoveTo(int x, int y) { actor->x = x; actor->y = y; };
};

#endif