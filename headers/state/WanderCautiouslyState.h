#ifndef __WANDER_CAUTIOUSLY_STATE_H_
#define __WANDER_CAUTIOUSLY_STATE_H_

#include "State.h"
#include "../Actor.h"
#include "../Point.h"
#include <string>
using namespace std;

/*
	WanderCautiouslyState
	======================
	Wanders through the world, avoiding corners of world, changes to RunAwayState if hunter is near.
*/
class WanderCautiouslyState : public State
{
public:
	/* Functions */
	WanderCautiouslyState(Actor* actor) : State(actor, "WanderCautiouslyState") {};
	~WanderCautiouslyState();

	void Update();
	Point GetNextPosition();
};

#endif