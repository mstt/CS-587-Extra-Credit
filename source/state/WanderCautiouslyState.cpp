#include "../headers/state/WanderCautiouslyState.h"
#include "../headers/World.h"

/** Public **/
void WanderCautiouslyState::Update()
{
	// TODO - query world, and start to run away if enemy is near
}

Point WanderCautiouslyState::GetNextPosition()
{
	Point p;
	p.x = actor->x + (rand() % 2 - 1);
	p.y = actor->y + (rand() % 2 - 1);

	while(p.x == actor->x && p.y == actor->y && p.x > 0 && p.x < World::GetInstance()->worldWidth && p.y > 0 && p.y < World::GetInstance()->worldHeight)
	{
		p.x = actor->x + (rand() % 2 - 1);
		p.y = actor->y + (rand() % 2 - 1);
	}

	return p;
}

WanderCautiouslyState::~WanderCautiouslyState()
{
}