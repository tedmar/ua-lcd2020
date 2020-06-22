/*
 *  act_timer.h
 *      timer management
 */

#define YELLOW_TIME 3
#define GREEN_TIME  15

void init_timer(void);
void set_timer( int secs );
void reset_timer( void );
int dec_timer( void );
int read_timer( void );

