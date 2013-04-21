#ifndef __WORLD_H_
#define __WORLD_H_

#include "Actor.h"
#include <vector>

/*
	World
	======================
	Grid that stores positions of actors.
*/
class World
{
private:
	Actor** cells;
	int cellsLength;

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
	Actor* GetActorAt(const int x, const int y);
	int GetNumActorsNear(int x, int y, int range);
	int GetNumActorsOfTypeNear(int x, int y, int range, int type);
	Actor** GetActorsNear(int x, int y, int range, int& size);
	void AddActorToWorld(Actor* actor);
	Actor* MoveActorInWorld(int x, int y, int newX, int newY);	//Returns actor that was consumed or NULL if nothing was consumed
	void RemoveActorFromWorld(Actor* actor);
	bool PointIsInWorld(int x, int y);
	void printWorld();
};

#endif