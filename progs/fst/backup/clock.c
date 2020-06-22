/*
 *  clock.c
 *      clock generation
 *      works in background
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 *  Project includes
 */

#include "clock.h"

/*
 *  Macros and defines
 */

#define CADENCE     1   // seconds

/*
 *  Static variables
 */

static unsigned seconds;            //  counts seconds from start
static void (*cback)( unsigned );   //  callback function 

/*
 *  Static functions
 */

/*
 *  sig_handler:
 *      signal handler
 *      Captures SIGALRM for calling callback functions
 *      Captures SIGINT for exiting program
 */

static void
sig_handler(int signum)
{
    switch( signum )
    {
        case SIGALRM:
            (*cback)(seconds++);  
            alarm(1);
            break;
        case SIGINT:
            printf("Program terminated at %u secs\n", seconds );
            exit( EXIT_SUCCESS );
            break;
        default:
            printf("Signal %d\n", signum );
            exit( EXIT_FAILURE );
    }
}

/*
 *  install_time_base:
 *      Inits time base and background system
 *      Receives and installs callback function
 *      Install signal to be captured
 *      Sets alarm to 1 second
 */


static void
install_time_base( void (*action)( unsigned ) )
{
    seconds = 0;
    signal(SIGALRM,sig_handler);
    signal(SIGINT,sig_handler);
    alarm(CADENCE);
    cback = action;
}

/*
 *  Public functions
 */

/*
 *  init_clock:
 *      Inits time base
 *      Informs callback function
 */

void
init_clock(void (*cback)( unsigned ) )
{
    install_time_base(cback);
}


