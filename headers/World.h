#ifndef __WORLD_H_
#define __WORLD_H_

#include "Actor.h"

/*
	World
	======================
	Grid that stores positions of actors.
*/
class World
{
public:
	/* Data */
	int worldWidth;
	int worldHeight;

	/* Functions */
	World(int width, int height) : worldWidth(width), worldHeight(height), cellsLength(width*height) { }
	~World();

	void Setup();
	Actor* GetActorAt(int x, int y);
	void AddActorToWorld(Actor* actor);

private:
	Actor** cells;
	int cellsLength;
};

#endif