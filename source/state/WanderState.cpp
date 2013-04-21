#include "../headers/state/WanderState.h"

/** Public **/
Point WanderState::GetNextPosition()
{
	Point p;
	p.x = actor->x + (rand() % 2 - 1);
	p.y = actor->y + (rand() % 2 - 1);

	while(p.x == actor->x && p.y == actor->y)
	{
		p.x = actor->x + (rand() % 2 - 1);
		p.y = actor->y + (rand() % 2 - 1);
	}

	return p;
}

WanderState::~WanderState()
{
}