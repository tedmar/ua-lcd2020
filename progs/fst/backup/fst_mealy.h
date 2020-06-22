/*
 *  fst_mealy.h
 *      fst type definitions and
 *      fst public functions
 */

/*
 *  --- Type definitions
 */

//  event object: event type and event text

typedef struct
{
    int event;
    char *event_name;
} event_t;

typedef struct
{
    int event;                      //  event received from system        
    int next_state;                 //  next_state
    void (*delta_func)(int event);  //  mealy output is made by a function
} delta_t;

typedef struct
{
    const char **st_names;          //  state names
    const event_t *events;          //  event list
    const int q0;                   //  initial state
    const delta_t **deltas;         //  transition table
    const int num_states;
    const int num_events;
} fst_mealy_t;

/*
 *  Public functions
 */

/*
 *  fst_mealy_init:
 *      receives parameters and inits FST
 */

void fst_mealy_init( const fst_mealy_t *init );

/*
 *  fst_mealy_transition:
 *      based on current state and
 *      event received from function call
 *      makes and shows the transition
 */

void fst_mealy_transition( int event );


