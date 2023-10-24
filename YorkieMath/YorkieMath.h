#pragma once

template <typename T, short int size> struct vector;

#ifdef YorkieMaths
#define YorkieMathsAPI __declspec(dllexport)
#else
#define YorkieMathsAPI __declspec(dllimport)
#endif