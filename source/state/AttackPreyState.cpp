#include "../headers/state/AttackPreyState.h"

/** Public **/
void AttackPreyState::Update()
{
	// TODO - move toward prey, switch to SearchForPreyState if prey is lost
}

Point AttackPreyState::GetNextPosition()
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

AttackPreyState::~AttackPreyState()
{
}