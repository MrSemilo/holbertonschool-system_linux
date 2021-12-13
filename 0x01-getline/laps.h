#ifndef _LAPS_H_
#define _LAPS_H_

#include<stdio.h>
#include <stdlib.h>

/**
 * struct car_s - cars
 *
 * @id: id number
 * @laps: laps
 * @next: next
**/
typedef struct car_s
{
	int id;
	int laps;
	struct car_s *next;
} car_t;

void race_state(int *id, size_t size);

#endif
