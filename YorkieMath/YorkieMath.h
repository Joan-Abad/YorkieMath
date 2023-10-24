#pragma once

#ifdef YorkieMaths
#define YorkieMathsAPI __declspec(dllexport)
#else
#define YorkieMathsAPI __declspec(dllimport)
#endif