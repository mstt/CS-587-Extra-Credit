#include "../headers/state/WanderCautiouslyState.h"
#include "../headers/World.h"

/** Public **/
void WanderCautiouslyState::Update()
{
	// Run away if other actors are near
	Actor** actorsNear = World::GetInstance()->GetActorsNear(actor->x, actor->y, 2);

	if(actorsNear != NULL)
	{
		nextState = "RunAwayState";
		delete[] actorsNear;
	}
}

Point WanderCautiouslyState::GetNextPosition()
{
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