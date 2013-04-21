#ifndef __WANDER_STATE_H_
#define __WANDER_STATE_H_

#include "State.h"
#include "../Actor.h"
#include "../Point.h"
#include <string>
using namespace std;

/*
	WanderState
	======================
	Wanders aimlessly through the world (i.e. moves randomly)
*/
class WanderState : public State
{
public:
	/* Functions */
	WanderState(Actor* actor) : State(actor, "WanderState") {};
	~WanderState();

	Point GetNextPosition();
};

#endif