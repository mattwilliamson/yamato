#pragma once

#include "yamato.h"

typedef enum {
    SUMO_INIT    = 0,  /**< Initial state   */
    SUMO_SLEEP   = 1,  /**< Sleep for 5s    */
    SUMO_SEEK    = 2,  /**< Look for enemy  */
    SUMO_ATTACK  = 3,  /**< Attack enemy    */
    SUMO_AVOID   = 4,  /**< Avoid line      */
    SUMO_KILLED  = 5   /**> Kill switch     */
} sumo_state_t;

void sumoStart(void);