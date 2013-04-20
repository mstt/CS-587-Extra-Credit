#include "../headers/Game.h"
#include <stdlib.h>

/** Public **/
void Game::Setup( SessionData* data )
{
	// @TODO: parse information from SessionData for initial game state
	printf( "Initializing game state" );

	//Create world
	world = new World(data->worldWidth, data->worldHeight);
	world->Setup();
	
	int hunterCount = data->actorCounts[EActorTypes::HUNTER];
	int dodoCount  = data->actorCounts[EActorTypes::DODO];
	int foxCount   = data->actorCounts[EActorTypes::FOX];
	actorCount = hunterCount + dodoCount + foxCount;

	actors = new Actor[actorCount];
	int i = 0;
	for(i; i < hunterCount; i++)
	{
		PlaceActorInWorld(&actors[i]);

		//assign actor a hunter controller
	}
	for(i; i < hunterCount + dodoCount; i++)
	{
		PlaceActorInWorld(&actors[i]);

		//assign actor a dodo controller
	}
	for(i; i < hunterCount + dodoCount + foxCount; i++)
	{
		PlaceActorInWorld(&actors[i]);

		//assign actor a fox controller
	}
}

void Game::Execute()
{
	// Begin activity
	isActive = true;

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
	for(int i = 0; i < actorCount; i++)
	{
		// move actors
	}
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