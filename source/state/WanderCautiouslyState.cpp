#include "../headers/state/WanderCautiouslyState.h"
#include "../headers/World.h"
#include "ActorTypes.h"
#include <vector>

/** Public **/
void WanderCautiouslyState::Update()
{
	// Run away if other actors are near
	numActorsNear = World::GetInstance()->GetNumActorsOfTypeNear(actor->x, actor->y, 2, EActorTypes::HUNTER);

	if(numActorsNear > 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "RunAwayState";
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point WanderCautiouslyState::GetNextPosition()
{
	actor->GetPotentialMoves();


	Point p;

	while(true)
	{
		p.x = actor->x + (rand() % 3 - 1);
		p.y = actor->y + (rand() % 3 - 1);

		if((p.x != actor->x || p.y != actor->y) && (p.x > 0 && p.x < World::GetInstance()->worldWidth - 1 && p.y > 0 && p.y < World::GetInstance()->worldHeight - 1))
			break;
	}

	return p;
}

WanderCautiouslyState::~WanderCautiouslyState()
{
}