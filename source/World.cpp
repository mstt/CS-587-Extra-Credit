#include "../headers/World.h"
#include <stdio.h>

void World::Setup()
{
	cells = new Actor*[cellsLength];
	for(int i = 0; i < cellsLength; i++)
	{
		cells[i] = NULL;
	}
}

World::~World()
{
	for(int i = 0; i < cellsLength ; i++)
	{
		delete cells[i];
		cells[i] = NULL;
	}

	delete[] cells;
	cells = NULL;
}

Actor* World::GetActorAt(int x, int y)
{
	return cells[x * worldWidth + y];
}

void World::AddActorToWorld(Actor* actor)
{
	cells[actor->x * worldWidth + actor->y] = actor;
}