#include "../headers/Actor.h"
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
	return (xDiff == 1 || yDiff == 1) && (xDiff < 2 && yDiff < 2);
}