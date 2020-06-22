/*
 *  fsm_moore.h
 *      generic moore fsm
 */

/*
 *  --- Type definitions
 */

/*
 *  Information type about each state
 *  implements type for Q fsm definition
 */


typedef struct
{
    int state;
    char *name_state;
    int final;
} info_t;

/*
 *  Alphabet conversion type about input
 *  implements type for Sigma definition
 */

typedef struct
{
    int input;
    int token;
    char *input_name;
} alphain_t;

/*
 *  Node type for each state
 *  implements type for delta
 */

typedef struct
{
    int alpha;
    int next_state;
} delta_t;

/*
 *  Moore object initialization
 */

typedef struct
{
    const info_t *Qstates;     /* Q..includes final states */
    const alphain_t *Sigma;    /* Sigma.. include text description */
    const int q0;              /* q0 initial state */
    const delta_t **deltas;    /* delta transition table */
    const int num_states;      /* states number    */
    const int num_alpha;
    const char **moore_out_texts;
} fsm_moore_t;

/*
 *  ----- Constants and macros
 */


/*
 *  Results of process_input()
 */

enum
{
    REJECTED, BAD_SYMBOL, ACCEPTED
};


/*
 *  fsm_moore_init:
 *      Receives data about the fsm tables and data
 */

int fsm_moore_init( const fsm_moore_t *init );

/*
 *  process_input:
 *      receives input string in s
 *      terminates on accept, reject or bad symbol
 *      In each state transition, prints it
 */

int process_input( char s[] );

/*
 *  termination;
 *      prints termination status based
 *      in argument
 */


void termination( int status );


