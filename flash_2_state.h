// -*- mode: c++ -*-
// Flashing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "flashing_state.h"

#ifndef __FLASH_2_STATE__
#define __FLASH_2_STATE__

class Flash2State: public FlashingState
{
 public:
  Flash2State(StateMachine *owner_machine);
  void enter(uint8_t *data);
  void mode_button(void);
  void red_button(void);
  void green_button(void);
  void blue_button(void);
};

#endif
