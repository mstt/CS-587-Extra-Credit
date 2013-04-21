#ifndef __ATTACK_PREY_STATE_H_
#define __ATTACK_PREY_STATE_H_

#include "State.h"
#include "../Actor.h"
#include "../Point.h"
#include <string>
using namespace std;

/*
	AttackPreyState
	======================
	Moves toward prey.
*/
class AttackPreyState : public State
{
public:
	/* Functions */
	AttackPreyState(Actor* actor) : State(actor, "AttackPreyState") {};
	~AttackPreyState();

	void Update();
	Point GetNextPosition();
};

#endif