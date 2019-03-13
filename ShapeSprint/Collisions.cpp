#include "Collisions.h"

boxSide BoxToBox(float x1, float y1, float height1, float width1, float x2, float y2, float height2, float width2)
{
	float maxX1, maxX2, maxY1, maxY2;
	float minX1, minX2, minY1, minY2;

	float c1, c2; // check 1 check 2

	maxX1 = x1 + (width1 / 2);
	maxX2 = x2 + (width2 / 2);
	maxY1 = y1 + (height1 / 2);
	maxY2 = y2 + (height2 / 2);

	minX1 = x1 - (width1 / 2);
	minX2 = x2 - (width2 / 2);
	minY1 = y1 - (height1 / 2);
	minY2 = y2 - (height2 / 2);

	//check no collision
	if (maxX1 < minX2 || minX1 > maxX2) return noSide;
	if (maxY1 < minY2 || minY1 > maxY2)  return noSide;

	//collision is true
	//check each side
	bool tr = false, br = false, tl = false, bl = false;
	
	if (maxX1 <= maxX2 && maxX1 >= minX2)
	{
		//bottom right point
		if (minY1 <= maxY2 && minY1 >= minY2)
		{
			br = true;
		}
		//top right point
		else if (maxY1 <= maxY2 && maxY1 >= minY2)
		{
			tr = true;
		}
	}
	else if (minX1 <= maxX2 && minX1 >= minX2)
	{
		//bottom left point
		if (minY1 <= maxY2 && minY1 >= minY2)
		{
			bl = true;
		}
		//top left point
		else if (maxY1 <= maxY2 && maxY1 >= minY2)
		{
			tl = true;
		}
	}

	//bottom left
	if (bl)
	{
		//either be top or right
		c1 = maxX2 - minX1; //if more of X value then top
		c2 = maxY2 - minY1; // if more of Y value then right
		if (c1 >= c2)
		{
			cout << "TOP SIDE" << endl;
			return topSide;
		}
		if (c1 <= c2)
		{
			cout << "RIGHT SIDE" << endl;
			return rightSide;
		}
	}
	if (tl)
	{
		//either be bottom or right
		c1 = maxX2 - minX1; //if more of X value then top
		c2 = maxY1 - minY2; // if more of Y value then right
		if (c1 >= c2)
		{
			cout << "BOTTOM SIDE" << endl;
			return bottomSide;
		}
		if (c1 <= c2)
		{
			cout << "RIGHT SIDE" << endl;
			return rightSide;
		}
	}
	if (br)
	{
		//either be top or left
		c1 = maxX1 - minX2; //if more of X value then top
		c2 = maxY2 - minY1; // if more of Y value then right
		if (c1 >= c2)
		{
			cout << "TOP SIDE" << endl;
			return topSide;
		}
		if (c1 <= c2)
		{
			cout << "LEFT SIDE" << endl;
			return leftSide;
		}
	}
	if (tr)
	{
		//either be bottom or left
		c1 = maxX1 - minX2; //if more of X value then top
		c2 = maxY1 - minY2; // if more of Y value then right
		if (c1 >= c2)
		{
			cout << "BOTTOM SIDE" << endl;
			return bottomSide;
		}
		if (c1 <= c2)
		{
			cout << "LEFT SIDE" << endl;
			return leftSide;
		}
	}
	cout << "NO SIDE" << endl;
	return noSide;
}