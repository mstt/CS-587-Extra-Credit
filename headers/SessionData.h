#ifndef __SESSION_DATA_H_
#define __SESSION_DATA_H_

#include "ActorTypes.h"

/*
	Session Data
	======================
	Provides initial data for starting a session of the test game.
*/
class SessionData
{
public:
	int actorCounts[EActorTypes::SIZE];		// Array of integer counts for each type of actor to spawn
	int worldWidth;
	int worldHeight;

	SessionData() : worldWidth(10), worldHeight(10) { }
};

#endif