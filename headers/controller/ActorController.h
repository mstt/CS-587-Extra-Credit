#ifndef __ACTORCONTROLLER_H_
#define __ACTORCONTROLLER_H_

#include "../Actor.h"
#include "../Point.h"
#include "../state/State.h"
#include <string>
#include <map>
using namespace std;

/*
	ActorController
	======================
	Abstract base class. Controls an actor.
*/
class ActorController
{
protected:
	Actor* actor;
	State* currentState;
	map<string, State*> stateMap;

public:
	/* Functions */
	ActorController(Actor* actor) : actor(actor) {};
	virtual ~ActorController() { stateMap.clear(); };

	void MoveTo(int x, int y) { actor->x = x; actor->y = y; }
	Point GetNextPosition() { return currentState->GetNextPosition(); }

	Actor* GetActor() { return actor; }
	string GetStateName() { return currentState->GetName(); }

	virtual void Update() {};
};

#endif