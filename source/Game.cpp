#include "../headers/Game.h"
#include "../headers/controller/HunterController.h"
#include "../headers/controller/DodoController.h"
#include "../headers/controller/FoxController.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/** Public **/
void Game::Setup( SessionData* data )
{
	// @TODO: parse information from SessionData for initial game state
	printf( "Initializing game state" );

	//Create world
	world = new World(data->worldWidth, data->worldHeight);
	world->Setup();
	
	//Set counts
	hunterCount = data->actorCounts[EActorTypes::HUNTER];
	dodoCount  = data->actorCounts[EActorTypes::DODO];
	foxCount   = data->actorCounts[EActorTypes::FOX];
	actorCount = hunterCount + dodoCount + foxCount;

	//Create controllers
	controllers = new ActorController*[actorCount];

	//Create actor array and place actors in world
	actors = new Actor[actorCount];
	int i, j;
	for(i = 0, j = 0; i < hunterCount; i++, j++)
	{
		actors[j].type = EActorTypes::HUNTER;
		PlaceActorInWorld(&actors[j]);
		controllers[j] = new HunterController(&actors[j]);
	}
	for(i = 0; i < dodoCount; i++, j++)
	{
		actors[j].type = EActorTypes::DODO;
		PlaceActorInWorld(&actors[j]);
		controllers[j] = new DodoController(&actors[j]);
	}
	for(i = 0; i < foxCount; i++, j++)
	{
		actors[j].type = EActorTypes::FOX;
		PlaceActorInWorld(&actors[j]);
		controllers[j] = new FoxController(&actors[j]);
	}
}

void Game::Execute()
{
	printf( "\nExecuting" );

	// Begin activity
	isActive = true;

	world->printWorld();

	// Continuous loop until the simulation has been told to terminate
	while ( isActive )
	{
		HandleFrame();

		// Game end condition
		if ( actorCount <= 1 || actors == NULL )
		{
			EndGame();
		}
	}
}

/** Private **/
void Game::HandleFrame()
{
	int i, j;
	for(i = 0; i < actorCount; i++)
	{
		int oldX = actors[i].x;
		int oldY = actors[i].y;
		Point p = controllers[i]->GetNextPosition();
		while(world->PointIsInWorld(p.x, p.y) == false)
		{
			p = controllers[i]->GetNextPosition();
		}

		Actor* actorToRemove = world->MoveActorInWorld(oldX, oldY, p.x, p.y);
		if(actorToRemove != NULL)
		{
			int i;
			for(i = 0; i < actorCount; i++)
			{
				if(controllers[i]->getActor() == actorToRemove)
				{
				}
			}
			//delete actorToRemove;
		}

		//printf("\nmoved to %i,%i", actors[i].x, actors[i].y);
	}

	world->printWorld();
	cin >> j;
}

void Game::EndGame()
{
	isActive = false;

	printf( "Game has ended" );

	//Free memory
	delete[] actors;
}

void Game::PlaceActorInWorld(Actor* actor)
{
	int x = rand() % world->worldWidth;
	int y = rand() % world->worldHeight;

	while(world->GetActorAt(x, y) != NULL)
	{
		x = rand() % world->worldWidth;
		y = rand() % world->worldHeight;
	}

	actor->x = x;
	actor->y = y;
	world->AddActorToWorld(actor);
}