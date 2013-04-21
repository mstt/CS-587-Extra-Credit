#ifndef __STATE_H_
#define __STATE_H_

#include "../Actor.h"
#include "../Point.h"
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
	string nextState;

public:
	/* Functions */
	State(Actor* actor, string name) : actor(actor), name(name) {};
	virtual ~State() {};
	void Setup();
	virtual void Update() {};
	virtual Point GetNextPosition() = 0;
	string getName() { return name; }
	string getNextState() { return nextState; }
};

#endif