#include "../headers/Game.h"
#include "../headers/HunterController.h"
#include "../headers/DodoController.h"
#include "../headers/FoxController.h"
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
	controllers = new IController*[actorCount];

	//Create actor array and place actors in world
	actors = new Actor[actorCount];
	int i, j;
	for(i = 0, j = 0; i < hunterCount; i++, j++)
	{
		actors[j].type = EActorTypes::HUNTER;
		PlaceActorInWorld(&actors[j]);
		controllers[j] = new HunterController(&actors[j]);	// TODO - change to HunterController
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
		controllers[j] = new FoxController(&actors[j]);	// TODO - change to FoxController
	}
}

void Game::Execute()
{
	printf( "\nExecuting" );

	// Begin activity
	isActive = true;

	// Continuous loop until the simulation has been told to terminate
	while ( isActive )
	{
		world->printWorld();

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
	printf("\nhandle frame");
	int i, j;
	for(i = 0; i < actorCount; i++)
	{
		printf("\ngetting next position for controller number %i", i);
		int oldX = actors[i].x;
		int oldY = actors[i].y;
		Point p = controllers[i]->GetNextPosition();
		while(world->PointIsInWorld(p.x, p.y) == false)
		{
			printf("\n x=%i, y=%i", p.x, p.y);
			p = controllers[i]->GetNextPosition();
			//cin >> j;
		}

		printf("\nmoving from %i,%i to %i,%i", oldX, oldY, p.x, p.y);
		controllers[i]->MoveTo(p.x, p.y);
		world->MoveActorInWorld(oldX, oldY, p.x, p.y);
		printf("\nmoved");
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