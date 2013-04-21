#include "../headers/state/SearchForPreyState.h"
#include "../headers/World.h"

/** Public **/
void SearchForPreyState::Update()
{
	// Go to attack mode if actors are near
	numActorsNear = World::GetInstance()->GetNumActorsNear(actor->x, actor->y, 2);

	if(numActorsNear > 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "AttackPreyState";
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point SearchForPreyState::GetNextPosition()
{
	// TODO - Think of smarter way to move
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