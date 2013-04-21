#ifndef __DODO_CONTROLLER_H_
#define __DODO_CONTROLLER_H_

#include "IController.h"
#include "Actor.h"
#include "Point.h"

/*
	DodoController
	======================
	Controls an actor. Moves randomly
*/
class DodoController : public IController
{
public:
	/* Data */
	Actor* actor;

	/* Functions */
	DodoController(Actor* actor) : actor(actor) { }
	Point GetNextPosition();
	void MoveTo(int x, int y) { actor->x = x; actor->y = y; };
};

#endif