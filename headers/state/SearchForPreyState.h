#ifndef __SEARCH_FOR_PREY_STATE_H_
#define __SEARCH_FOR_PREY_STATE_H_

#include "State.h"
#include "../Actor.h"
#include "../Point.h"
#include <string>
using namespace std;

/*
	SearchForPreyState
	======================
	Roams world searching for prey
*/
class SearchForPreyState : public State
{
public:
	/* Functions */
	SearchForPreyState(Actor* actor) : State(actor, "SearchForPreyState") {};
	~SearchForPreyState();

	void Update();
	Point GetNextPosition();
};

#endif