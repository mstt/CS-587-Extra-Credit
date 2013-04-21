#include "../headers/controller/DodoController.h"
#include "../headers/state/State.h"
#include "../headers/state/WanderState.h"
#include <stdlib.h>
#include <stdio.h>

/** Public **/
DodoController::DodoController(Actor* actor) : ActorController(actor)
{
	stateMap["WanderState"] = new WanderState(actor);
	currentState = stateMap["WanderState"];
}

DodoController::~DodoController()
{
	delete stateMap["WanderState"];
}