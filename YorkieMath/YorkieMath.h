#pragma once

template <typename T, short int size> struct vector;
template <typename T, short int roms, short int columns> struct matrix;

#ifdef YorkieMaths
#define YorkieMathsAPI __declspec(dllexport)
#else
#define YorkieMathsAPI __declspec(dllimport)
#endif