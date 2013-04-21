#ifndef __HUNTER_CONTROLLER_H_
#define __HUNTER_CONTROLLER_H_

#include "ActorController.h"
#include "Actor.h"
#include "Point.h"

/*
	HunterController
	======================
	Controls an actor.
*/
class HunterController : public ActorController
{
public:
	/* Functions */
	HunterController(Actor* actor) : ActorController(actor) { }
	Point GetNextPosition();
};

#endif