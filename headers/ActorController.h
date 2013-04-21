#ifndef __ACTORCONTROLLER_H_
#define __ACTORCONTROLLER_H_

#include "Actor.h"
#include "Point.h"

/*
	ActorController
	======================
	Controls an actor.
*/
class ActorController
{
protected:
	Actor* actor;
public:
	/* Functions */
	ActorController(Actor* actor) : actor(actor) {};
	Actor* getActor() { return actor; }
	void MoveTo(int x, int y) { actor->x = x; actor->y = y; };
	virtual Point GetNextPosition() = 0;
};

#endif