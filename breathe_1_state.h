// -*- mode: c++ -*-
// Static colour state
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "state.h"

#ifndef __BREATHE_1_STATE__
#define __BREATHE_1_STATE__

class Breathe1State: public State
{
 public:
  Breathe1State(StateMachine *owner_machine);
  void enter(uint8_t *data);
  void mode_button(void);
  void red_button(void);
  void green_button(void);
  void blue_button(void);
  void tick(uint32_t now);

 private:
  uint8_t compute_fractional(uint8_t colour);
  void update_fractional(uint8_t r, uint8_t g, uint8_t b);
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint32_t step_time;
  uint32_t step_interval;
  float breathe_delta;
  float breathe_value;
};

#endif
