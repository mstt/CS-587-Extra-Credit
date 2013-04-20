#include <stdio.h>
#include "../headers/Game.h"
#include "../headers/ActorTypes.h"

/**
	Main entry point for the application.
**/
int main( int argc, char* argv[] )
{
	Game game;

	// @NOTE: This is just an example setup of session data, this can and will change when
	// we are testing. Feel free to change this as you test and develop.
	SessionData sessionData;
	sessionData.actorCounts[EActorTypes::HUNTER] = 1;
	sessionData.actorCounts[EActorTypes::DODO] = 1;
	sessionData.actorCounts[EActorTypes::FOX] = 1;

	sessionData.worldHeight = 10;
	sessionData.worldWidth = 10;

	// Pass starting data to game
	game.Setup( &sessionData );

	// Game now handles all application execution
	game.Execute();

	return 0;
}