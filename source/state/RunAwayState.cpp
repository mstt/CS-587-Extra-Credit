#include "../headers/state/RunAwayState.h"
#include "../headers/World.h"
#include "../headers/ActorTypes.h"
#include <math.h>

/** Public **/
void RunAwayState::Update()
{
	// If no hunters around, switch to WanderCautiouslyState
	numActorsNear = World::GetInstance()->GetNumActorsOfTypeNear(actor->x, actor->y, 2, EActorTypes::HUNTER);

	if(numActorsNear == 0)
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
	//printf("\ngetting next position RunAwayState: %i,%i", actor->x, actor->y); 
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

	//printf("\nbest fox move: %i", bestMoveScore);
	return actor->potentialMoves[bestMoveIndex];
}

int RunAwayState::EvaluatePosition(int newX, int newY, int range)
{
	//printf("\nevaluating position %i,%i", newX, newY);
	int score = 0;

	// If hunter is at position, it is worst possible move
	if(World::GetInstance()->GetActorAt(newX, newY) != NULL && World::GetInstance()->GetActorAt(newX, newY)->type == EActorTypes::HUNTER)
	{
		//printf("\nfound worst move");
		return -1000000;
	}

	//Avoid corners
	if(World::GetInstance()->IsInCornerWithRange(newX, newY, 2))
		score -= 1;

	//printf("\n no hunter is at position");
	int i, j;
	for(i = actor->x - range; i <= actor->x + range; i++)
	{
		for(j = actor->y - range; j <= actor->x + range; j++)
		{
			if((i != actor->x || j != actor->y) && World::GetInstance()->PointIsInWorld(i, j) &&
				World::GetInstance()->PointsAreWithinRange(i, j, newX, newY, range) && World::GetInstance()->GetActorAt(i, j) != NULL)
			{
				Actor* actorNear = World::GetInstance()->GetActorAt(i, j);

				if(actorNear->type == EActorTypes::HUNTER)
				{
					double distance = sqrt( (double)((newX-i)*(newX-i) + (newY-j)*(newY-j)));
					//printf("\ndistance: %f", 100 / distance);

					//printf("\nhunter within range");
					score -= (int)(1000 / distance);
				}
				else
				{
					//printf("\nno hunter within range");
					score += 2;
				}
			}
		}
	}

	//printf("\nevaluated position %i,%i: %i", newX, newY, score);
	return score;
}

RunAwayState::~RunAwayState()
{
}