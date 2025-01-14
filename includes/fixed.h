#ifndef __FIXED_GUARD__
#define __FIXED_GUARD__

#include "global-includes.h"

#define STATE_HIDDEN 1
#define STATE_VISIBLE 2

typedef unsigned char state;

typedef struct {
	char *star;
	size_t starSize;
	unsigned short interval;
	long long lastFlip;
	state starState;
	_2DPoint position;
} FixedStar;

#endif
