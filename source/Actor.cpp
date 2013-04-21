#include "../headers/Actor.h"
#include "../headers/ActorTypes.h"
#include "../headers/World.h"
#include <math.h>

/** Public **/
const bool Actor::DoesCollide( const Actor* actor )
{
	// We assume actors are 1 world unit in width and height and move 1 unit per turn
	return actor->x == x && actor->y == y;
}

const bool Actor::CanMoveTo(const int x2, const int y2)
{
	int xDiff = abs(x - x2);
	int yDiff = abs(y - y2);
	bool isOneSpaceAway =  (xDiff == 1 || yDiff == 1) && (xDiff < 2 && yDiff < 2);

	bool inWorld = World::GetInstance()->PointIsInWorld(x2, y2);

	Actor* actorAtNewCell = World::GetInstance()->GetActorAt(x2, y2);

	// Anything can move onto empty cell
	if(actorAtNewCell == NULL)
	{
		return isOneSpaceAway && inWorld;
	}

	// Hunters can't move onto hunters
	if(type == EActorTypes::HUNTER)
	{
		return isOneSpaceAway && inWorld && actorAtNewCell->type != EActorTypes::HUNTER;
	}

	// Dodos and foxes can't move onto other actors
	return false;
}

int Actor::GetPotentialMoves()
{
	potentialMoves.clear();

	int i, j;
	for(i = x - 1; i < x + 1; i++)
	{
		for(j = y - 1; j < y + 1; j++)
		{
			if(i != x && j != y && CanMoveTo(i, j))
				potentialMoves.push_back(Point(i, j));
		}
	}

	return potentialMoves.size();
}