/*
 *  game_def.h
 *      definitions for tennis scoring
 */

/*
 *  State enumeration
 */

enum states
{
    LOVE, S15_LOVE, S30_LOVE, S40_LOVE, GAME_IN,
    S30_15, S40_15, S40_30, ADV_IN,
    S15_ALL, S30_ALL, DEUCE,
    SLOVE_15, SLOVE_30, SLOVE_40, GAME_OUT,
    S15_30, S15_40, S30_40, ADV_OUT,
    NUM_STATES
};

/*
 *  input alpha classification
 */

enum
{
    PS, PO,
    NUM_ALPHA
};

/*
 *  Input alphabet conversion and print text
 *  (Sigma from FSM definition)
 *  Form part of FSM consgtructor
 */

static const alphain_t alpha_in[] =
{
    {   's',    PS, "server"    },
    {   'o',    PO, "opponent"  }
};

/*
 *  Each state transition table
 */

static const delta_t love[] =
{
    {   PS, S15_LOVE    },
    {   PO, SLOVE_15    }
};

static const delta_t s15_love[] =
{
    {   PS, S30_LOVE    },
    {   PO, S15_ALL     }
};

static const delta_t s30_love[] =
{
    {   PS, S40_LOVE    },
    {   PO, S30_15      }
};

static const delta_t s40_love[] =
{
    {   PS, GAME_IN     },
    {   PO, S40_15      },
};

static const delta_t game_in[] =
{
};

static const delta_t s30_15[] =
{
    {   PS, S40_15      },
    {   PO, S30_ALL      }
};

static const delta_t s40_15[] =
{
    {   PS, GAME_IN     },
    {   PO, S40_30      }
};

static const delta_t s40_30[] =
{
    {   PS, GAME_IN     },
    {   PO, DEUCE       }
};

static const delta_t adv_in[] =
{
    {   PS, GAME_IN     },
    {   PO, DEUCE       }
};

static const delta_t s15_all[] =
{
    {   PS, S30_15      },
    {   PO, S15_30      }
};

static const delta_t s30_all[] =
{
    {   PS, S40_30      },
    {   PO, S30_40      }
};

static const delta_t deuce[] =
{
    {   PS, ADV_IN      },
    {   PO, ADV_OUT     }
};

static const delta_t slove_15[] =
{
    {   PS, S15_ALL     },
    {   PO, SLOVE_30    }
};

static const delta_t slove_30[] =
{
    {   PS, S15_30      },
    {   PO, SLOVE_40    }
};

static const delta_t slove_40[] =
{
    {   PS, S15_40      },
    {   PO, GAME_OUT    }
};

static const delta_t game_out[] =
{
};

static const delta_t s15_30[] =
{
    {   PS, S30_ALL     },
    {   PO, S15_40      }
};

static const delta_t s15_40[] =
{
    {   PS, S30_40      },
    {   PO, GAME_OUT    }
};

static const delta_t s30_40[] =
{
    {   PS, DEUCE       },
    {   PO, GAME_OUT    }
};

static const delta_t adv_out[] =
{
    {   PS, DEUCE       },
    {   PO, GAME_OUT    }
};

/*
 *  Complete transition table
 *  (delta from definition of FSM)
 *  Is part of FSM constructor
 */

static const delta_t *deltas[] =
{
    love, s15_love, s30_love, s40_love, game_in,
    s30_15, s40_15, s40_30, adv_in,
    s15_all, s30_all, deuce,
    slove_15, slove_30, slove_40, game_out,
    s15_30, s15_40, s30_40, adv_out
};

/*
 *  Moore output for each state
 */

static const char *moore_outputs[] =
{
    "0-0", "15-0", "30-0", "40-0", "server win",
    "30-15", "40-15", "40-30", "adv_server",
    "15-15", "30-30", "deuce",
    "0-15", "0-30", "0-40", "opponent win",
    "15-30", "15-40", "30-40", "adv_opponent"
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
    {   LOVE,       "LOVE",     0   },
    {   S15_LOVE,   "S15_LOVE", 0   },
    {   S30_LOVE,   "S30_LOVE", 0   },
    {   S40_LOVE,   "S40_LOVE", 0   },
    {   GAME_IN,    "GAME_IN",  1   },
    {   S30_15,     "S30_15",   0   },
    {   S40_15,     "S40_15",   0   },
    {   S40_30,     "S40_30",   0   },
    {   ADV_IN,     "ADV_IN",   0   },
    {   S15_ALL,    "S15_ALL",  0   },
    {   S30_ALL,    "S30_ALL",  0   },
    {   DEUCE,      "DEUCE",    0   },
    {   SLOVE_15,   "SLOVE_15", 0   },
    {   SLOVE_30,   "SLOVE_30", 0   },
    {   SLOVE_40,   "SLOVE_40", 0   },
    {   GAME_OUT,   "GAME_OUT", 1   },
    {   S15_30,     "S15_30",   0   },
    {   S15_40,     "S15_40",   0   },
    {   S30_40,     "S30_40",   0   },
    {   ADV_OUT,    "ADV_OUT",  0   }

};


/*
 *  Init value
 */

const fsm_moore_t finit =
{
    info,
    alpha_in,
    LOVE,
    deltas,
    NUM_STATES,
    NUM_ALPHA,
    moore_outputs
};



