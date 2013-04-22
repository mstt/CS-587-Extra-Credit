#include "../headers/state/AttackPreyState.h"
#include "../headers/World.h"
#include "../headers/ActorTypes.h"

/** Public **/
void AttackPreyState::Update()
{
	// Switch to SearchForPreyState if prey is lost
	numActorsNear = World::GetInstance()->GetNumActorsNotOfTypeNear(actor->x, actor->y, 2, EActorTypes::HUNTER);

	if(numActorsNear == 0)
	{
		status = EStateStatuses::ACTOR_NEAR;
		nextState = "SearchForPreyState";
		//printf("\nswitching to state: %s", nextState.c_str());
	}
	else
	{
		status = EStateStatuses::NO_ACTORS_NEAR;
	}
}

Point AttackPreyState::GetNextPosition()
{
	//printf("\ngetting next position AttackPreyState: %i,%i", actor->x, actor->y);
	Point p(actor->x, actor->y);

	actor->GetPotentialMoves();
	int numMoves = actor->potentialMoves.size();
	//printf("\npotential moves: %i", numMoves);

	// If no moves available, don't move
	if(numMoves < 1)
		return Point(actor->x, actor->y);

	int i, bestMoveIndex, bestMoveScore;
	for(i = 0, bestMoveIndex = 0, bestMoveScore = -9999; i < numMoves; i++)
	{
		int moveScore = EvaluatePosition(actor->potentialMoves[i].x, actor->potentialMoves[i].y, 2);

		if(moveScore > bestMoveScore)
		{
			bestMoveScore = moveScore;
			bestMoveIndex = i;
		}
	}

	return actor->potentialMoves[bestMoveIndex];
}

int AttackPreyState::EvaluatePosition(int newX, int newY, int range)
{
	//printf("\nevaluating position %i,%i", newX, newY);
	int score = 0;

	// If non-hunter is at position, it is best possible move
	if(World::GetInstance()->GetActorAt(newX, newY) != NULL && World::GetInstance()->GetActorAt(newX, newY)->type != EActorTypes::HUNTER)
	{
		//printf("\nmoving to kill");
		return 1000000;
	}

	//Avoid corners
	if(World::GetInstance()->IsInCornerWithRange(newX, newY, 2))
		score -= 1;

	//printf("\nno actor is at position");
	int i, j;
	for(i = actor->x - range; i <= actor->x + range; i++)
	{
		for(j = actor->y - range; j <= actor->x + range; j++)
		{
			// If (i,j) has actor near (newX, newY)
			if((i != actor->x || j != actor->y) && World::GetInstance()->PointIsInWorld(i, j) &&
				World::GetInstance()->PointsAreWithinRange(i, j, newX, newY, range) && World::GetInstance()->GetActorAt(i, j) != NULL)
			{
				Actor* actorNear = World::GetInstance()->GetActorAt(i, j);

				if(actorNear->type != EActorTypes::HUNTER)
				{
					//printf("\nprey within range");
					score += 5;
				}
				else
				{
					//printf("\nno prey within range");
					score -= 2;
				}
			}
		}
	}

	//printf("\nevaluated position %i,%i: %i", newX, newY, score);
	return score;
}

AttackPreyState::~AttackPreyState()
{
}