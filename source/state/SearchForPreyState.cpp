#include "../headers/state/SearchForPreyState.h"
#include "../headers/World.h"
#include "ActorTypes.h"

/** Public **/
void SearchForPreyState::Update()
{
	// Go to attack mode if actors are near
	numActorsNear = World::GetInstance()->GetNumActorsNotOfTypeNear(actor->x, actor->y, 2, EActorTypes::HUNTER);

	if(numActorsNear > 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "AttackPreyState";
		//printf("\nswitching to state: %s", nextState.c_str());
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point SearchForPreyState::GetNextPosition()
{
	//printf("\ngetting next position SearchForPreyState"); 

	actor->GetPotentialMoves();
	int numMoves = actor->potentialMoves.size();

	if(numMoves > 0)
		return actor->potentialMoves[rand() % numMoves];
	else
		return Point(actor->x, actor->y);
}

SearchForPreyState::~SearchForPreyState()
{
}