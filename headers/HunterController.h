#ifndef __HUNTER_CONTROLLER_H_
#define __HUNTER_CONTROLLER_H_

#include "IController.h"
#include "Actor.h"
#include "Point.h"

/*
	HunterController
	======================
	Controls an actor.
*/
class HunterController : public IController
{
public:
	/* Data */
	Actor* actor;

	/* Functions */
	HunterController(Actor* actor) : actor(actor) { }
	Point GetNextPosition();
	void MoveTo(int x, int y) { actor->x = x; actor->y = y; };
};

#endif