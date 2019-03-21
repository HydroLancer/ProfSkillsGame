#include "Collisions.h"
<<<<<<< HEAD

boxMovementSide HorizontalCollision(float x1, float y1, float height1, float width1, float x2, float y2, float height2, float width2)
{
	float maxX1, maxX2, maxY1, maxY2;
	float minX1, minX2, minY1, minY2;
	//
	maxX1 = x1 + (width1 / 2); // e.g player x1
	maxY1 = y1 + (height1 / 2);
	minX1 = x1 - (width1 / 2);
	minY1 = y1 - (height1 / 2);
	//
	maxX2 = x2 + (width2 / 2); // e.g cube x2
	maxY2 = y2 + (height2 / 2);
	minX2 = x2 - (width2 / 2);
	minY2 = y2 - (height2 / 2);

	boxMovementSide side = noMSide;

	if (maxY1 > minY2 && minY1 < maxY2)
=======
boxMovementSide movementCollision(float x1, float y1, float height1, float width1, float x2, float y2, float height2, float width2)
{
	float maxX1, maxX2, maxY1, maxY2;
	float minX1, minX2, minY1, minY2;
	maxX1 = x1 + (width1 / 2); // MaxX1 etc is the e.g player x1
	maxY1 = y1 + (height1 / 2);
	minX1 = x1 - (width1 / 2);
	minY1 = y1 - (height1 / 2);
	maxX2 = x2 + (width2 / 2); //MaxX2 etc is the e.g cube x2
	maxY2 = y2 + (height2 / 2);
	minX2 = x2 - (width2 / 2);
	minY2 = y2 - (height2 / 2);
	boxMovementSide side = noMSide;
	if (maxY1 > minY2 && minY1 < maxY2) // check if a collision has happened
>>>>>>> CollisionTesting
	{
		if (maxX1 > minX2 && minX1 < maxX2)
		{
			if (minX1 < minX2) // leftside
<<<<<<< HEAD
			{
				side = leftSide;
			}
			else if (maxX1 > maxX2)// rightside
			{
=======
			{
				side = leftSide;
			}
			else if (maxX1 > maxX2)// rightside
			{
>>>>>>> CollisionTesting
				side = rightSide;
			}
		}
	}
<<<<<<< HEAD
		
=======

>>>>>>> CollisionTesting
	return(side);
} 
boxJumpingSide VerticalCollision(float x1, float y1, float height1, float width1, float x2, float y2, float height2, float width2)
{
	float maxX1, maxX2, maxY1, maxY2;
	float minX1, minX2, minY1, minY2;
	maxX1 = x1 + (width1 / 2); // e.g player x1
	maxY1 = y1 + (height1 / 2);
	minX1 = x1 - (width1 / 2);
	minY1 = y1 - (height1 / 2);
	maxX2 = x2 + (width2 / 2); // e.g cube x2
	maxY2 = y2 + (height2 / 2);
	minX2 = x2 - (width2 / 2);
	minY2 = y2 - (height2 / 2);
	boxJumpingSide side = noJSide;
	if (maxX1 > minX2 && minX1 < maxX2) // check if a collision has happened
	{
		if (maxY1 >= minY2 && minY1 <= maxY2)
		{
			if (maxY1 > maxY2) // topside
			{
				side = topSide;
			}
			else if (minY1 < minY2) // bottomside
			{
				side = bottomSide;
			}
		}
	}
	
	return(side);
}