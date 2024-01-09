#pragma once
#include "../YorkieMath.h"
#include "Vector.h"

template <typename T> 
struct line <T, 2>
{
	using Vec2 = vector<T, 2>;

	//The direction the line has
	using Vec2 direction;

	//Where the line starts
	using Vec2 origin; 
};