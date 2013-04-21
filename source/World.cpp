#include "../headers/World.h"
#include "../headers/ActorTypes.h"
#include <stdio.h>
using namespace std;

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

Actor* World::MoveActorInWorld(int x, int y, int newX, int newY)
{
	Actor* actor = cells[newX * worldWidth + newY];
	cells[newX * worldWidth + newY] = cells[x * worldWidth + y];
	cells[x * worldWidth + y] = NULL;

	cells[newX * worldWidth + newY]->x = newX;
	cells[newX * worldWidth + newY]->y = newY;

	return actor;
}

void World::RemoveActorFromWorld(Actor* actor)
{
	cells[actor->x * worldWidth + actor->y] = NULL;
}

bool World::PointIsInWorld(int x, int y)
{
	return x >= 0 && x < worldWidth && y >= 0 && y < worldHeight;
}

void World::printWorld()
{
	printf("\n");
	printf("-----------------------------------------");
	printf("\n");
	int i, j;
	for(i = 0; i < worldWidth; i++)
	{
		printf("|");
		for(j = 0; j < worldHeight; j++)
		{
			Actor* actor = GetActorAt(i, j);
			if(actor == NULL)
			{
				printf(" - |");
			}
			else
			{
				switch(actor->type)
				{
				case EActorTypes::HUNTER:
					printf(" H |");
					break;

				case EActorTypes::DODO:
					printf(" D |");
					break;

				case EActorTypes::FOX:
					printf(" F |");
					break;
				}
			}
		}
		printf("\n");
		printf("-----------------------------------------");
		printf("\n");
	}
}