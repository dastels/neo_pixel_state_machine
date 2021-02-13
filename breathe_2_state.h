// -*- mode: c++ -*-
// Breathing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "breathing_state.h"

#ifndef __BREATHE_2_STATE__
#define __BREATHE_2_STATE__

class Breathe2State: public BreathingState
{
 public:
  Breathe2State(StateMachine *owner_machine);
  void enter(uint8_t *data);
  void mode_button(void);
  void red_button(void);
  void green_button(void);
  void blue_button(void);
};

#endif
