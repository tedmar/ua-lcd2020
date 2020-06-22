/*
 *  actions.h
 *      Transition action routines
 *      Other routines related with fst
 */

/*
 *  fst transition action routines
 */

void ew_yellow( int event );
void ns_green( int event );
void ns_yellow( int event );
void ew_green( int event );

/*
 *  ew_in_go:
 *      initial state at power up
 */

void ew_in_go(void);

/*
 *  show_lights
 *      Shows lights of both intersection
 */

void show_lights( void );

