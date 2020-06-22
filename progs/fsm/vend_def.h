/*
 *  vend_def.h
 */

/*
 *  State enumeration
 */

enum
{
    S0, S1, S2, S3,
    NUM_STATES
};

/*
 *  input alpha classification
 */

enum
{
    P1, P2,
    NUM_ALPHA
};

/*
 *  Input alphabet conversion and print text
 *  (Sigma from FSM definition)
 *  Form part of FSM consgtructor
 */

static const alphain_t alpha_in[] =
{
    {   '1',    P1, "Coin $1"  },
    {   '2',    P2, "Coin $2"  }
};

/*
 *  Each state transition table
 */

static const delta_t S0_state[] =
{
    {   P1, S1  },
    {   P2, S2  }
};

static const delta_t S1_state[] =
{
    {   P1, S2  },
    {   P2, S3  }
};

static const delta_t S2_state[] =
{
    {   P1, S3  },
    {   P2, S3  }
};

static const delta_t S3_state[] =
{
};

/*
 *  Complete transition table
 *  (delta from definition of FSM)
 *  Is part of FSM constructor
 */

static const delta_t *deltas[] =
{
    S0_state, S1_state, S2_state, S3_state
};

/*
 *  Moore output for each state
 */

static const char *moore_outputs[] =
{
    "No expending", "No expending", "No expending", "Expending"
};

/*
 *  Information state table
 *  Here are information abot states
 *  including which one is acceptor
 *  (Q of FSM definition)
 *  Form part of FSM constructor
 */

static const info_t info[] =
{
    {   S0, "S0",   0   },
    {   S1, "S1",   0   },
    {   S2, "S2",   0   },
    {   S3, "S3",   1   }
};

//static int initial_state = S0;


/*
 *  Init value
 */

const fsm_moore_t finit =
{
    info,
    alpha_in,
    S0,
    deltas,
    NUM_STATES,
    NUM_ALPHA,
    moore_outputs
};



