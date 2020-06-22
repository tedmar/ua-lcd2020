/*
 *  traffic.c
 *      Implements traffic machine
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

/*
 *  Project includes
 */

#include "fst_mealy.h"
#include "clock.h"
#include "act_timer.h"
#include "actions.h"
#include "traffic_def.h"

/*
 *  Macros
 */

#define forever for(;;)

/*
 *  Static functions
 */

/*
 *  clear_screen
 */

static void
clear_screen( void )
{
    assert( system("clear") == 0 );
}

/*
 *  tick_func
 *      executed each second in background
 *      decrement timer and if elapsed
 *      then make a trasition and refresh semaphores
 */

static void
tick_func( unsigned time )
{
//    putchar('.');
    printf("%2d\r", read_timer() );
    fflush(stdout);
    if( dec_timer() )
    {
        putchar('\r');
        fst_mealy_transition(T1);
        show_lights();
    }
}


/*
 *  Public functions
 */

int
main(void)
{
    clear_screen();
    fst_mealy_init( &finit );
    init_timer();
    init_clock(tick_func);
    ew_in_go();         // set initial conditions

    forever
    ;                   // all is done in background
}
   


