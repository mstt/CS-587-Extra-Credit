#include "../headers/state/RunAwayState.h"

/** Public **/
void RunAwayState::Update()
{
	// TODO - query world, if no enemies around, switch to WanderCautiouslyState
}

Point RunAwayState::GetNextPosition()
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

RunAwayState::~RunAwayState()
{
}