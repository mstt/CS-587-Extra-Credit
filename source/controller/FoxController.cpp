#include "../headers/controller/FoxController.h"
#include "../headers/state/State.h"
#include "../headers/state/WanderCautiouslyState.h"
#include "../headers/state/RunAwayState.h"
#include <stdlib.h>
#include <stdio.h>

/** Public **/
FoxController::FoxController(Actor* actor) : ActorController(actor)
{
	stateMap["WanderCautiouslyState"] = new WanderCautiouslyState(actor);
	stateMap["RunAwayState"] = new RunAwayState(actor);
	currentState = stateMap["WanderCautiouslyState"];
}

void FoxController::Update()
{
	currentState->Update();

	//printf("\nnext state: %s", currentState->GetNextState().c_str());

	//Change state if current state says you should
	if(stateMap.find(currentState->GetNextState()) != stateMap.end())
	{
		currentState = stateMap[currentState->GetNextState()];
		currentState->Setup();
	}
}

FoxController::~FoxController()
{
	delete stateMap["WanderCautiouslyState"];
	delete stateMap["RunAwayState"];
}