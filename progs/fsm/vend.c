/*
 *  vend.c
 *      Implements vending machine
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "fsm_moore.h"
#include "vend_def.h"

static void
clear_screen( void )
{
    if( isatty(STDOUT_FILENO) )
        assert( system("clear") == 0 );
}


/*
 *  Public functions
 */

int
main(void)
{
    char buffer[512];

    clear_screen();
    fsm_moore_init( &finit );
    while( fgets( buffer, sizeof(buffer), stdin ) != NULL && buffer[0] != '\n' )
        termination(process_input( buffer ));
    fprintf( stderr, "No input....terminating\n" );
    return EXIT_SUCCESS;
}
   


