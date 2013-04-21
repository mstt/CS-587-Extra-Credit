#ifndef __ACTORS_NEAR_H_
#define __ACTORS_NEAR_H_

#include "ActorTypes.h"

/*
	ActorsNear
	======================
	Used to store how many of each type of actor is near.
*/
struct ActorsNear
{
	int actorCounts[EActorTypes::SIZE];
};

#endif