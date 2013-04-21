#include "../headers/state/WanderState.h"
#include "../headers/World.h"

/** Public **/
Point WanderState::GetNextPosition()
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

WanderState::~WanderState()
{
}