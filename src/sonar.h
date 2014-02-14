#pragma once

#include "yamato.h"

#define US_TO_CM(microseconds) microseconds / 58.0

unsigned long sonarLastDistance(void);
void sonarInit(void);