#ifndef _SONAR_H_
#define _SONAR_H_

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "chrtclib.h"

#include "yamato.h"

#define US_TO_CM(microseconds) microseconds / 58.0

#endif

unsigned long sonarLastDistance(void);
void sonarInit(void);