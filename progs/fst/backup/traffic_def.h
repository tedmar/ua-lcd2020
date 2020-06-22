/*
 *  traffic_def.h
 *      Traffic problem definitions to FST
 *      This file is included in traffic.c
 *      for clarity
 */

/*
 *  State enumeration
 */

enum
{
    EW_GO, EW_STOPPING, NS_GO, NS_STOPPING,
    NUM_STATES
};

/*
 *  input alpha classification
 */

enum
{
    T1, 
    NUM_EVENTS
};

/*
 *  Input alphabet list and print text
 */

static const event_t events[] =
{
    {   T1, "Timer"  }
};

/*
 *  Each state transition table
 */

static const delta_t ew_go[] =
{
    {   T1, EW_STOPPING, ew_yellow   }
};

static const delta_t ew_stopping[] =
{
    {   T1, NS_GO, ns_green  }
};

static const delta_t ns_go[] =
{
    {   T1, NS_STOPPING, ns_yellow  }
};

static const delta_t ns_stopping[] =
{
    {   T1, EW_GO, ew_green  }
};

/*
 *  Complete transition table
 *  (delta from definition of FSM)
 */

static const delta_t *deltas[] =
{
    ew_go, ew_stopping, ns_go, ns_stopping
};

/*
 *  Information state table
 *  Here are information about states
 */

static const char *states_names[] =
{
    "EW_GO", "EW_STOPPING", "NS_GO", "NS_STOPPING"
};


/*
 *  Init value
 */

const fst_mealy_t finit =
{
    states_names,
    events,
    EW_GO,
    deltas,
    NUM_STATES,
    NUM_EVENTS,
};



