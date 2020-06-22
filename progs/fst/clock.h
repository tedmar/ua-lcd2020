/*
 *  clock.h
 *      clock generation
 *      works in background
 */

/*
 *  init_clock:
 *      Inits time base
 *      Informs callback function
 */

void init_clock( void (*func)( unsigned ));

