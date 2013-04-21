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
private:
	World() {}
public:
	/* Data */
	static World* world;
	static bool instanceFlag;
	int worldWidth;
	int worldHeight;

	/* Functions */
	static World* GetInstance();
	~World();

	void Setup(int width, int height);
	Actor* GetActorAt(int x, int y);
	Actor** GetActorsNear(int x, int y, int range);
	void AddActorToWorld(Actor* actor);
	Actor* MoveActorInWorld(int x, int y, int newX, int newY);	//Returns actor if it was moved on top of
	void RemoveActorFromWorld(Actor* actor);
	bool PointIsInWorld(int x, int y);
	void printWorld();

private:
	Actor** cells;
	int cellsLength;
};

#endif