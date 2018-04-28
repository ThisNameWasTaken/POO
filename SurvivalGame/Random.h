#pragma once

#include <random>
#include <time.h>
#include <limits>

/**
 * @returns a random integer within the given range
 * @param max - the maximum value which can be returned
 * @param min - the minimum value which can be returned
 */
static int random(int max = INT_MAX, int min = 0) {
	return rand() % max + 1 + min;
}