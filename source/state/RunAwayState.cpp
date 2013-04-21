#include "../headers/state/RunAwayState.h"
#include "../headers/World.h"

/** Public **/
void RunAwayState::Update()
{
	// If no actors around, switch to WanderCautiouslyState
	Actor** actorsNear = World::GetInstance()->GetActorsNear(actor->x, actor->y, 2);

	if(actorsNear == NULL)
	{
		nextState = "WanderCautiouslyState";
	}
	else
	{
		delete[] actorsNear;
	}
}

Point RunAwayState::GetNextPosition()
{
	Point p;

	while(true)
	{
		p.x = actor->x + (rand() % 3 - 1);
		p.y = actor->y + (rand() % 3 - 1);

		if(World::GetInstance()->PointIsInWorld(p.x, p.y) && (p.x != actor->x || p.y != actor->y))
			break;
	}

	return p;
}

RunAwayState::~RunAwayState()
{
}