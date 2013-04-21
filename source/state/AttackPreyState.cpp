#include "../headers/state/AttackPreyState.h"
#include "../headers/World.h"

/** Public **/
void AttackPreyState::Update()
{
	// TODO - move toward prey, switch to SearchForPreyState if prey is lost
}

Point AttackPreyState::GetNextPosition()
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

AttackPreyState::~AttackPreyState()
{
}