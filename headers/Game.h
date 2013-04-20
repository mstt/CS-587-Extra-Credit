#ifndef __GAME_H_
#define __GAME_H_

#include <stdio.h>
#include "SessionData.h"
#include "Actor.h"

/*
	Game
	======================
	Basic logic handler for setting up state and maintaining game session.
*/
class Game
{
public:
	Game() : isActive(false) { }
	void Setup( SessionData* data );	// Initializes game state
	void Execute();						// Begins game loop execution

private:
	/* Data */
	bool isActive;						// Flag indicating whether the game will continue or not
	Actor* actors;						// Array of actors in memory (feel free to change this to another data structure)
	int actorCount;						// Count of actors in the actors array

	/* Functions */
	void HandleFrame();					// Runs logic needed per-frame
	void EndGame();						// Stops game execution
};

#endif