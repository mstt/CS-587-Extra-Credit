#include "../headers/state/RunAwayState.h"
#include "../headers/World.h"
#include <math.h>

/** Public **/
void RunAwayState::Update()
{
	// If no actors around, switch to WanderCautiouslyState
	numActorsNear = World::GetInstance()->GetNumActorsNear(actor->x, actor->y, 2);

	if(numActorsNear > 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "WanderCautiouslyState";
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point RunAwayState::GetNextPosition()
{
	Actor** actorsNear = World::GetInstance()->GetActorsNear(actor->x, actor->y, 2, numActorsNear);
	Point p;

	// Move away from actors
	int xDiff = 0, yDiff = 0;
	int i;
	for(i = 0; i < numActorsNear; i++)
	{
		xDiff += actor->x - actorsNear[i]->x;
		yDiff += actor->y - actorsNear[i]->y;
	}

	if(xDiff != 0) xDiff /= abs(xDiff);
	if(yDiff != 0) yDiff /= abs(yDiff);

	if(xDiff != 0 || yDiff != 0)
	{
		xDiff /= abs(xDiff);
		yDiff /= abs(yDiff);
	}
	else
	{
		while(true)
		{
			p.x = actor->x + (rand() % 3 - 1);
			p.y = actor->y + (rand() % 3 - 1);

			if(World::GetInstance()->PointIsInWorld(p.x, p.y) && (p.x != actor->x || p.y != actor->y))
				break;
		}
	}

	return p;
}

RunAwayState::~RunAwayState()
{
}