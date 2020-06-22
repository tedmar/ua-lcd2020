/*
 *  fsm_moore.c
 *      implements generic moore fsm
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fsm_moore.h"

/*
 *  ---- Static const
 */

/*
 *  result text based in termination of process_input
 */

static const char *term_text[] =
{
    "REJECTED", "BAD_SYMBOL", "ACCEPTED"
};

/*
 *  saves pointer to fsm moore initialization
 */

static const fsm_moore_t *finit;

/*
 *  ---- Static variables
 */

static char *alpha_name;

/*
 *  ---- Static functions
 */

/*
 *  get_alpha:
 *      Given the external input, return internal
 *      alphabet (0...num_alpha-1)
 *      Also, reads and saves in alpha_name the external name
 *
 *      If c doesn't pertain to alphabet, return negative
 */

static int
get_alpha( int c )
{
    int i;

    for( i = 0; i < finit->num_alpha; ++i )
    {
        if( c == (finit->Sigma)[i].input )
        {
            alpha_name = (finit->Sigma)[i].input_name;
            return (finit->Sigma)[i].token;
        }
    }
    return -1;
}

/*
 *  print_transition:
 *      prints data of transition from
 *      'state' to 'new_state'
 *      What prints depends if stdout is redirected or not
 */


static void
print_transition( int state, int new_state )
{
    if( isatty( STDOUT_FILENO ) )
        printf( "\"%-8s\" -> %-8s -> \"%-8s\" = \"%s\"\n",
            (finit->Qstates)[state].name_state,
            alpha_name,
            (finit->Qstates)[new_state].name_state ,
            (finit->moore_out_texts)[new_state] );
    else
        printf( "\"%s\" ", (finit->Qstates)[state].name_state );

}

/*
 *  print_input:
 *      Prints a header before reading input
 *      The header prints the input string to analyze only
 *      if stdin is redirected from a file
 */

static void
print_input( char s[] )
{
    if( !isatty( STDIN_FILENO ) )
        printf( "%s", s );
}

 /*
 *  --- Public functions
 */

/*
 *  fsm_moore_init:
 *      Receives data about the fsm tables and data
 */

int
fsm_moore_init( const fsm_moore_t *init )
{
    finit = init;
    return 1;
}



/*
 *  process_input:
 *      receives input string in s
 *      terminates on accept, reject or bad symbol
 *      In each state transition, prints it
 */

int
process_input( char s[] )
{
    int state, new_state, alpha, i;

    state = finit->q0;

    print_input(s);

    for( i = 0; s[i] != '\n' && s[i] != '\0'; ++i )
    {
        if( ( alpha = get_alpha(s[i]) ) >= 0 )
        {
            new_state = (finit->deltas)[state][alpha].next_state;
            print_transition( state, new_state );
            state = new_state;
            if( (finit->Qstates)[state].final )
                return ACCEPTED;
        } else
            return BAD_SYMBOL;
    }
    return REJECTED;
}

/*
 *  Results of process_input()
 */

void
termination( int status )
{
    printf("%s...\n", term_text[status]);
}



