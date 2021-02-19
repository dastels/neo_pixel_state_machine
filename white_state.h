// -*- mode: c++ -*-
// All white colour state
//
// Copyright (c) 2021 Dave Astels
// Revision to add white state by Rob Mohr

#include "state_machine.h"
#include "state.h"

#ifndef __WHITE_STATE__
#define __WHITE_STATE__

class WhiteState: public State
{
 public:
WhiteState(StateMachine *owner_machine);
  void enter(uint8_t *data);
  void mode_button();
  void red_button();
  void green_button();
  void blue_button();
};

#endif
