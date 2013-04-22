#ifndef __RUN_AWAY_STATE_H_
#define __RUN_AWAY_STATE_H_

#include "State.h"
#include "../Actor.h"
#include "../Point.h"
#include <string>
using namespace std;

/*
	RunAwayState
	======================
	Runs away from a predator
*/
class RunAwayState : public State
{
public:
	/* Functions */
	RunAwayState(Actor* actor) : State(actor, "RunAwayState") {};
	~RunAwayState();

	void Update();
	Point GetNextPosition();
	int EvaluatePosition(int newX, int newY, int range);
};

#endif