#ifndef __HUNTER_CONTROLLER_H_
#define __HUNTER_CONTROLLER_H_

#include "ActorController.h"
#include "../Actor.h"
#include "../Point.h"

/*
	HunterController
	======================
	Controls an actor. Hunts prey.
*/
class HunterController : public ActorController
{
public:
	/* Functions */
	HunterController(Actor* actor);
	~HunterController();
	void Update();
};

#endif