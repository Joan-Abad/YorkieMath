#pragma once
#include "../YorkieMath.h"
#include "Vector.h"

template <typename T> 
struct line <T, 3>
{
	using Vec3 = vector<T, 3>;

	//The direction the line has
	using Vec3 direction;

	//Where the line starts
	using Vec3 origin; 
};