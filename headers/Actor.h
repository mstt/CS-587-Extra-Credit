#ifndef __ACTOR_H_
#define __ACTOR_H_

#include "Point.h"
#include <vector>
using namespace std;

/*
	Actor
	======================
	Main in-world representation of a physical object
*/
class Actor
{
public:
	/* Data */
	int x;											// x coordinate in world space
	int y;											// y coordinate in world space
	bool alive;
	int type;
	vector<Point> potentialMoves;

	/* Functions */
	Actor() : x(0), y(0), alive(true) { }
	const bool DoesCollide( const Actor* actor );	// Determines if two actors are colliding
	const bool CanMoveTo(const int x, const int y);	// Returns true if actor can move to cell at (x, y)
	int GetPotentialMoves();						// Fills potentialMoves vector, returns size
};

#endif
