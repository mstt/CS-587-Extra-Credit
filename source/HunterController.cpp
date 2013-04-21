#include "../headers/HunterController.h"
#include <stdlib.h>
#include <stdio.h>

/** Public **/
Point HunterController::GetNextPosition()
{
	printf("\ngetting position");
	Point p;
	p.x = actor->x + (rand() % 2 - 1);
	p.y = actor->y + (rand() % 2 - 1);

	while(p.x == actor->x && p.y == actor->y)
	{
		p.x = actor->x + (rand() % 2 - 1);
		p.y = actor->y + (rand() % 2 - 1);
	}

	return p;
}