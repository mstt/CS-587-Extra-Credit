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
	void MoveActorInWorld(int x, int y, int newX, int newY);
	void RemoveActorFromWorld(Actor* actor);
	bool PointIsInWorld(int x, int y);
	void printWorld();

private:
	Actor** cells;
	int cellsLength;
};

#endif