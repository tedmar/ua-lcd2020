/*
 *  act_timer.c
 *      timer management
 */
#include <stdio.h>
#include <stdlib.h>

#include "act_timer.h"

static int timer_secs;  // timer cell

void
init_timer(void)
{
    reset_timer();
}

void
set_timer( int secs )
{
    timer_secs = secs;
}

void
reset_timer( void )
{
    set_timer(0);
}

int
dec_timer( void )
{

    if( timer_secs && --timer_secs == 0 )
        return 1;
    return 0;
}

int
read_timer( void )
{
    return timer_secs;
}



