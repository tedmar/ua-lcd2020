/*
 *  fst_mealy.c
 *      fst public functions
 */

#include <stdio.h>
#include <stdlib.h>

#include "fst_mealy.h"

/*
 *  --- Static const
 */

/*
 *  saves pointer to fst mealy initialization
 */

static const fst_mealy_t *finit;

/*
 *  static variables
 */

static int state;

/*
 *  Public functions
 */


/*
 *  fst_mealy_init:
 *      receives parameters and inits FST
 */

void
fst_mealy_init( const fst_mealy_t *init )
{
    finit = init;
    state = finit->q0;
}

/*
 *  fst_mealy_transition:
 *      based on current state and
 *      event received from function call
 *      makes and shows the transition
 */

void
fst_mealy_transition( int event )
{
    int new_state;

    new_state = (finit->deltas)[state][event].next_state;
    printf( "%s + %s -> %s\n",
        (finit->st_names)[state],
        (finit->events)[event].event_name,
        (finit->st_names)[new_state] );
    (*(finit->deltas)[state][event].delta_func)(event);
    state = new_state;
}




