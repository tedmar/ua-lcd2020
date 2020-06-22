/*
 *  lights.c
 *      Simulates traffic lights in
 *      both intersections
 */

#include "lights.h"

//  One char for each light

static unsigned char sema[2];

/*
 *  read_light:
 *      reads one of traffic lights
 */

int
read_light(int which)
{
    return sema[which];
}

/*
 *  set_light:
 *      writes one of traffic lights
 */

void
set_light(int which, int value)
{
    sema[which] = value;
}

