// -*- mode: c++ -*-
// Static colour state
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "state.h"

#ifndef __STATIC_STATE__
#define __STATIC_STATE__

class StaticState: public State
{
 public:
  StaticState(StateMachine *owner_machine);
  void enter(void *data);
  void mode_button();
  void red_button();
  void green_button();
  void blue_button();
 private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

#endif
