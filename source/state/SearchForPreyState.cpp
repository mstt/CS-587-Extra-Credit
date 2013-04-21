#include "../headers/state/SearchForPreyState.h"
#include "../headers/World.h"

/** Public **/
void SearchForPreyState::Update()
{
	// TODO - query world, switch to AttackPreyState if prey is near
}

Point SearchForPreyState::GetNextPosition()
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

SearchForPreyState::~SearchForPreyState()
{
}