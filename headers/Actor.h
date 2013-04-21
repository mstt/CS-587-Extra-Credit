#ifndef __ACTOR_H_
#define __ACTOR_H_

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
	int type;

	/* Functions */
	Actor() : x(0), y(0) { }
	const bool DoesCollide( const Actor* actor );	// Determines if two actors are colliding
};

#endif
