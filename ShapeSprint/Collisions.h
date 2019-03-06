#pragma once
#include "ControlHeader.h"
enum boxSide { leftSide, rightSide, topSide, bottomSide, noSide }; // Determines which side of the 'box' has been hit
boxSide BoxToBox(float x1, float y1, float height1, float width1, float x2, float y2, float height2, float width2); // Box-to-box collision detection