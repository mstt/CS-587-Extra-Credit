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

		if(actor->CanMoveTo(p.x, p.y))
			break;
	}

	return p;
}

WanderState::~WanderState()
{
}