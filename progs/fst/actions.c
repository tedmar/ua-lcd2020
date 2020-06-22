/*
 *  actions.c
 *      Transition action routines
 *      Other routines related with fst
 */

#include <stdio.h>

/*
 *  Project includes
 */

#include "actions.h"
#include "lights.h"
#include "act_timer.h"

/*
 *  fst transition action routines
 */

void
ew_yellow( int event )
{
    int current;

    current = read_light(EW);
    set_light(EW, current | YELLOW );

    set_timer(YELLOW_TIME);
}

void
ns_green( int event )
{
    set_light(NS, GREEN);
    set_light(EW, RED);

    set_timer(GREEN_TIME);
}

void
ns_yellow( int event )
{
    int current;

    current = read_light(NS);
    set_light(NS, current | YELLOW );

    set_timer(YELLOW_TIME);
}

void
ew_green( int event )
{
    set_light(EW, GREEN);
    set_light(NS, RED);

    set_timer(GREEN_TIME);
}

/*
 *  ew_in_go:
 *      initial state at power up
 */

void
ew_in_go(void)
{
    set_light(EW, GREEN);
    set_light(NS, RED);
    set_timer(GREEN_TIME);
}

/*
 *  show_lights
 *      Shows lights of both intersections
 */

void
show_lights( void )
{
    int lights;

    lights = read_light(EW);
    printf( "EW: %c%c%c\n",
        ( lights & RED )    ? 'R': '_',
        ( lights & YELLOW ) ? 'W': '_',
        ( lights & GREEN )  ? 'G': '_');

    lights = read_light(NS);
    printf( "NS: %c%c%c\n",
        ( lights & RED )    ? 'R': '_',
        ( lights & YELLOW ) ? 'W': '_',
        ( lights & GREEN )  ? 'G': '_' );
}





