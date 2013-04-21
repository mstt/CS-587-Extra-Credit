#include "../headers/state/SearchForPreyState.h"

/** Public **/
void SearchForPreyState::Update()
{
	// TODO - query world, switch to AttackPreyState if prey is near
}

Point SearchForPreyState::GetNextPosition()
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

SearchForPreyState::~SearchForPreyState()
{
}