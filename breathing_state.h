// -*- mode: c++ -*-
// Breathing state with colour adjust
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "state.h"

#ifndef __BREATHING_STATE__
#define __BREATHING_STATE__

class BreathingState: public State
{
 public:
  BreathingState(StateMachine *owner_machine, char *name, float delta, int interval);
  void tick(uint32_t now);

 protected:
  uint8_t compute_fractional(uint8_t colour);
  void update_fractional(uint8_t r, uint8_t g, uint8_t b);

  uint32_t step_time;
  uint32_t step_interval;
  float breathe_delta;
  float breathe_value;
};

#endif
