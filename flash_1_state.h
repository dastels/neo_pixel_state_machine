// -*- mode: c++ -*-
// Flashing state with colour adjust
//
// Copyright (c) 2021 Dave Astels

#include "state_machine.h"
#include "flashing_state.h"

#ifndef __FLASH_1_STATE__
#define __FLASH_1_STATE__

class Flash1State: public FlashingState
{
 public:
  Flash1State(StateMachine *owner_machine);
  void enter(uint8_t *data);
  void mode_button(void);
  void red_button(void);
  void green_button(void);
  void blue_button(void);
};

#endif
