#include "../headers/controller/HunterController.h"
#include "../headers/state/State.h"
#include "../headers/state/SearchForPreyState.h"
#include "../headers/state/AttackPreyState.h"
#include <stdlib.h>
#include <stdio.h>

/** Public **/
HunterController::HunterController(Actor* actor) : ActorController(actor)
{
	stateMap["SearchForPreyState"] = new SearchForPreyState(actor);
	stateMap["AttackPreyState"] = new AttackPreyState(actor);
	currentState = stateMap["SearchForPreyState"];
}

void HunterController::Update()
{
}

HunterController::~HunterController()
{
	delete stateMap["SearchForPreyState"];
	delete stateMap["AttackPreyState"];
}