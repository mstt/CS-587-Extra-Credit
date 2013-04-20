#include "../headers/Game.h"

/** Public **/
void Game::Setup( SessionData* data )
{
	// @TODO: parse information from SessionData for initial game state
	printf( "Initializing game state" );
	
	int hunterCount = data->actorCounts[EActorTypes::HUNTER];
	int dodoCount  = data->actorCounts[EActorTypes::DODO];
	int foxCount   = data->actorCounts[EActorTypes::FOX];
	actorCount = hunterCount + dodoCount + foxCount;

	actors = new Actor[actorCount];
	int i = 0;
	for(i; i < hunterCount; i++)
	{
		//assign actor a hunter controller
		//place actor
	}
	for(i; i < hunterCount + dodoCount; i++)
	{
		//assign actor a dodo controller
		//place actor
	}
	for(i; i < hunterCount + dodoCount + foxCount; i++)
	{
		//assign actor a fox controller
		//place actor
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
		// act
	}
}

void Game::EndGame()
{
	isActive = false;

	printf( "Game has ended" );
}