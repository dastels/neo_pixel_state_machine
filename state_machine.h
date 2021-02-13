// -*- mode: c++ -*-
// State Machine
//
// Copyright (c) 2021 Dave Astels

#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "state.h"

#define MAX_STATES (8)

class StateMachine {
 protected:
  char *_initial_state_name;
  State *_current_state;

 private:
  State *_states[MAX_STATES];
  int _number_of_states;

  State *find_state(char *state_name);

 public:
  StateMachine();
  bool add_state(State *state);
  bool reset();
  bool go_to_state(char *state_name, uint8_t *data=nullptr);
  void tick(uint32_t now);
  void mode_button();
  void red_button();
  void green_button();
  void blue_button();
  const char *current_state_name();
};

#endif
