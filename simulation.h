#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "lbody.h"

static const double G = 6.67408e-11;

void simulate_step(lbody_t *list, int timestep);

#endif
