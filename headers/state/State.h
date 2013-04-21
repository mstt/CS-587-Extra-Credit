#ifndef __STATE_H_
#define __STATE_H_

#include "../Actor.h"
#include "../Point.h"
#include "StateStatuses.h"
#include <string>
using namespace std;

/*
	State
	======================
	State for AI.
*/
class State
{
protected:
	Actor* actor;
	string name;
	int status;
	string nextState;
	int numActorsNear;

public:
	/* Functions */
	State(Actor* actor, string name) : actor(actor), name(name), status(EStateStatuses::NO_ACTORS_NEAR), nextState(""), numActorsNear(0) {}
	virtual ~State() {}

	void Setup();
	virtual void Update() {}
	virtual Point GetNextPosition() = 0;
	virtual int evaluatePosition(int newX, int newY, int range) { return 0; };		//Evaluates new position based off actors near current position

	string getName() const { return name; }
	int getStatus() const { return status; }
	string getNextState() const { return nextState; }
};

#endif