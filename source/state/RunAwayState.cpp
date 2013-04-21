#include "../headers/state/RunAwayState.h"
#include "../headers/World.h"
#include "../headers/ActorTypes.h"
#include <math.h>

/** Public **/
void RunAwayState::Update()
{
	// If no actors around, switch to WanderCautiouslyState
	numActorsNear = World::GetInstance()->GetNumActorsNear(actor->x, actor->y, 2);

	if(numActorsNear > 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "WanderCautiouslyState";
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point RunAwayState::GetNextPosition()
{
	Point p(actor->x, actor->y);

	actor->GetPotentialMoves();
	int numMoves = actor->potentialMoves.size();

	// If no moves available, don't move
	if(numMoves < 1)
		return Point(actor->x, actor->y);

	int i, bestMoveIndex, bestMoveScore;
	for(i = 0, bestMoveIndex = 0, bestMoveScore = -9999; i < numMoves; i++)
	{
		int moveScore = evaluatePosition(actor->potentialMoves[i].x, actor->potentialMoves[i].y, 2);

		if(moveScore > bestMoveScore)
		{
			bestMoveScore = moveScore;
			bestMoveIndex = i;
		}
	}

	return actor->potentialMoves[bestMoveIndex];
}

int RunAwayState::evaluatePosition(int newX, int newY, int range)
{
	int score = 0;

	// If hunter is at position, it is worst possible move
	if(World::GetInstance()->GetActorAt(newX, newY) != NULL && World::GetInstance()->GetActorAt(newX, newY)->type == EActorTypes::HUNTER)
		return -1000000;

	int i, j;
	for(i = actor->x - range; i < range; i++)
	{
		for(j = actor->y - range; j < range; j++)
		{
			//Avoid corners
			if(World::GetInstance()->IsInCornerWithRange(i, j, 2))
				score -= 1;

			if(World::GetInstance()->GetActorAt(i, j) != NULL)
			{
				Actor* actorNear = World::GetInstance()->GetActorAt(i, j);

				if(actorNear->type == EActorTypes::HUNTER)
				{
					score -= 5;
				}
				else
				{
					score += 2;
				}
			}
		}
	}

	return score;
}

RunAwayState::~RunAwayState()
{
}