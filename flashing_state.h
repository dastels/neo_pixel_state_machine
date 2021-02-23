// -*- mode: c++ -*-
// Flashing state with colour adjust
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "state.h"

#ifndef __FLASHING_STATE__
#define __FLASHING_STATE__

class FlashingState: public State
{
 public:
  FlashingState(StateMachine *owner_machine, char *name, float delta, int interval);
  void tick(uint32_t now);

 protected:
  void update_fractional(uint8_t r, uint8_t g, uint8_t b, uint8_t w);

  uint32_t step_time;
  uint32_t step_interval;
  float step_delta;
  bool flash_state;
};

#endif
