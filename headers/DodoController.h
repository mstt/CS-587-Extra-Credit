#ifndef __DODO_CONTROLLER_H_
#define __DODO_CONTROLLER_H_

#include "Actor.h"

/*
	DodoController
	======================
	Controls an actor. Moves randomly
*/
class DodoController
{
public:
	/* Data */
	Actor* actor;

	/* Functions */
	DodoController(Actor* pActor) : actor(pActor) { }
	void move();
};

#endif