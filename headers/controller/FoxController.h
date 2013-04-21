#ifndef __FOX_CONTROLLER_H_
#define __FOX_CONTROLLER_H_

#include "ActorController.h"
#include "../Actor.h"
#include "../Point.h"

/*
	FoxController
	======================
	Controls an actor.
*/
class FoxController : public ActorController
{
public:
	/* Functions */
	FoxController(Actor* actor);
	~FoxController();
	void Update();
};

#endif