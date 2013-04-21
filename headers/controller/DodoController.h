#ifndef __DODO_CONTROLLER_H_
#define __DODO_CONTROLLER_H_

#include "ActorController.h"
#include "../Actor.h"
#include "../Point.h"

/*
	DodoController
	======================
	Controls an actor. Moves randomly
*/
class DodoController : public ActorController
{
public:
	/* Functions */
	DodoController(Actor* actor);
	~DodoController();
};

#endif