#pragma once
#include "ControlHeader.h"
enum boxSide { leftSide, rightSide, frontSide, backSide, noSide };
boxSide sphereToBox(float sphereX, float sphereZ,float sphereRadius, float sphereOldX, float sphereOldZ, float boxX, float boxZ, float length, float width); // collsion detection
//boxSide noCollision(float sphereX, float sphereZ, float sphereRadius, float sphereOldX, float sphereOldZ, float boxX, float boxZ, float length, float width);