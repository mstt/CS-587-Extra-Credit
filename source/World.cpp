#include "../headers/World.h"
#include "../headers/ActorTypes.h"
#include <stdio.h>
#include <math.h>
using namespace std;

World* World::world = NULL;
bool World::instanceFlag = false;

World* World::GetInstance()
{
	if(!instanceFlag)
	{
		world = new World();
		instanceFlag = true;
		return world;
	}
	else
	{
		return world;
	}
}

void World::Setup(int width, int height)
{
	worldWidth = width;
	worldHeight = height;
	cellsLength = width*height;

	cells = new Actor*[cellsLength];
	for(int i = 0; i < cellsLength; i++)
	{
		cells[i] = NULL;
	}
}

Actor* World::GetActorAt(int x, int y)
{
	return cells[x * worldWidth + y];
	//return cells[y * worldHeight + x];
}

int World::GetNumActorsNear(int x, int y, int range)
{
	int numActors = 0;
	int i, j;

	for(i = x - range; i <= x + range; i++)
	{
		for(j = y - range; j <= y + range; j++)
		{
			if((i != x || j != y) && PointIsInWorld(i, j) && GetActorAt(i, j) != NULL)
			{
				++numActors;
			}
		}
	}

	return numActors;
}

int World::GetNumActorsOfTypeNear(int x, int y, int range, int type)
{
	int numActors = 0;
	int i, j;

	for(i = x - range; i <= x + range; i++)
	{
		for(j = y - range; j <= y + range; j++)
		{
			if((i != x || j != y) && PointIsInWorld(i, j) && GetActorAt(i, j) != NULL && GetActorAt(i, j)->type == type)
			{
				++numActors;
			}
		}
	}

	return numActors;
}

int World::GetNumActorsNotOfTypeNear(int x, int y, int range, int type)
{
	int numActors = 0;
	int i, j;

	for(i = x - range; i <= x + range; i++)
	{
		for(j = y - range; j <= y + range; j++)
		{
			if((i != x || j != y) && PointIsInWorld(i, j) && GetActorAt(i, j) != NULL && GetActorAt(i, j)->type != type)
			{
				++numActors;
			}
		}
	}

	return numActors;
}

Actor** World::GetActorsNear(int x, int y, int range, int& numActors)
{
	numActors = 0;
	int i, j;

	//First find out how many actors are within range
	for(i = x - range; i <= x + range; i++)
	{
		for(j = y - range; j <= y + range; j++)
		{
			if((i != x || j != y) && PointIsInWorld(i, j) && GetActorAt(i, j) != NULL)
			{
				++numActors;
			}
		}
	}

	if(numActors == 0)
		return NULL;

	Actor** actorsNear = new Actor*[numActors];

	//Now add actors to array
	int index = 0;
	for(i = x - range; i <= x + range; i++)
	{
		for(j = y - range; j <= y + range; j++)
		{
			if((i != x || j != y) && PointIsInWorld(i, j) && GetActorAt(i, j) != NULL)
			{
				actorsNear[index++] = GetActorAt(i, j);
			}
		}
	}

	return actorsNear;
}

void World::AddActorToWorld(Actor* actor)
{
	cells[actor->x * worldWidth + actor->y] = actor;
}

Actor* World::MoveActorInWorld(int x, int y, int newX, int newY)
{
	if(x == newX && y == newY)
		return NULL;

	//printf("\nmoving actor in world from %i,%i to %i,%i", x, y, newX, newY);
	Actor* actorThatIsMoving = cells[x * worldWidth + y];
	Actor* actorAtNewCell = cells[newX * worldWidth + newY];
	Actor* actorThatIsConsumed = NULL;

	// If an actor is going to be consumed
	if(actorAtNewCell != NULL)
	{
		//printf("\nsetting consumed");
		if(actorThatIsMoving->type == EActorTypes::HUNTER)
		{
			//printf("\nconsuming");
			actorThatIsConsumed = actorAtNewCell;
			cells[newX * worldWidth + newY] = cells[x * worldWidth + y];
			cells[newX * worldWidth + newY]->x = newX;
			cells[newX * worldWidth + newY]->y = newY;
		}
		else if(actorAtNewCell->type == EActorTypes::HUNTER)
		{
			//printf("\nbeing consumed");
			actorThatIsConsumed = actorThatIsMoving;
		}
		else
		{
			printf("\ninvalid move, not moving");
			return NULL;
		}
	}
	else
	{
		cells[newX * worldWidth + newY] = cells[x * worldWidth + y];
		cells[newX * worldWidth + newY]->x = newX;
		cells[newX * worldWidth + newY]->y = newY;
	}

	cells[x * worldWidth + y] = NULL;

	return actorThatIsConsumed;
}

void World::RemoveActorFromWorld(Actor* actor)
{
	cells[actor->x * worldWidth + actor->y] = NULL;
}

bool World::PointIsInWorld(int x, int y)
{
	return x >= 0 && x < worldWidth && y >= 0 && y < worldHeight;
}

bool World::PointsAreWithinRange(int x, int y, int x2, int y2, int range)
{
	return (abs(x - x2) <= range) && (abs(y - y2) <= range);
}

bool World::IsInCornerWithRange(int x, int y, int range)
{
	return (x < range && y < range) || (x < range && y >= worldHeight - range) ||
		   (x >= worldWidth - range && y < range) || (x >= worldWidth - range && y >= worldHeight - range);
}

void World::printWorld()
{
	int i, j, k;
	printf("\n");

	for(k = 0; k < worldWidth; k++)
		printf("----");
	printf("-");

	printf("\n");
	for(i = 0; i < worldHeight; i++)
	{
		printf("|");
		for(j = 0; j < worldWidth; j++)
		{
			Actor* actor = GetActorAt(i, j);
			if(actor == NULL)
			{
				printf(" - |");
			}
			else
			{
				//printf(" A |");

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
		
		for(k = 0; k < worldWidth; k++)
			printf("----");
		printf("-");

		printf("\n");
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

	instanceFlag = false;
}