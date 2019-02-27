#include "Collisions.h"
boxSide sphereToBox(float sphereX, float sphereZ, float sphereRadius, float sphereOldX, float sphereOldZ, float boxX, float boxZ, float length, float width)
{
	float minX, maxX, minZ, maxZ;
	minX = boxX - (width / 2) - sphereRadius; // works out the area covered that the car can collide with
	maxX = boxX + (width / 2) + sphereRadius;
	minZ = boxZ - (length / 2) - sphereRadius;
	maxZ = boxZ + (length / 2) + sphereRadius;
	boxSide result = noSide;
	if ((sphereX > minX) && (sphereX < maxX) && (sphereZ > minZ) && (sphereZ < maxZ)) // if a collision has happened
	{
		if (sphereOldX < minX)
		{
			result = leftSide;
		}
		else if (sphereOldX > maxX)
		{
			result = rightSide;
		}
		else if (sphereOldZ < minZ)
		{
			result = frontSide;
		}
		else if (sphereOldZ > maxZ)
		{
			result = backSide;
		}
	}
	return(result); // collision on what side

}
//boxSide noCollision(float sphereX, float sphereZ, float sphereRadius, float sphereOldX, float sphereOldZ, float boxX, float boxZ, float length, float width)
//{
//	float minX, maxX, minZ, maxZ;
//	minX = boxX - (width / 2) - sphereRadius; // works out the area covered that the car can collide with
//	maxX = boxX + (width / 2) + sphereRadius;
//	minZ = boxZ - (length / 2) - sphereRadius;
//	maxZ = boxZ + (length / 2) + sphereRadius;
//	boxSide result = noSide;
//	if ((sphereX > minX) && (sphereX < maxX) && (sphereZ > minZ) && (sphereZ < maxZ)) // if a collision has happened
//	{
//		if (sphereOldX > minX)
//		{
//			result = leftSide;
//		}
//		else if (sphereOldX < maxX)
//		{
//			result = rightSide;
//		}
//		else if (sphereOldZ > minZ)
//		{
//			result = frontSide;
//		}
//		else if (sphereOldZ < maxZ)
//		{
//			result = backSide;
//		}
//	}
//	return(result); // collision on what side
//
//}