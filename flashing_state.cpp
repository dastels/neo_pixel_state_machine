// -*- mode: c++ -*-
// Breathing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "flashing_state.h"

FlashingState::FlashingState(StateMachine *machine, char *name, float delta, int interval)
  : State(machine, name)
  , step_delta(delta)
  , step_interval(interval)
  , step_time(0)
{
}


void FlashingState::update_fractional(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
  if (flash_state) {
    update_neopixels(r, g, b, w);
  } else {
    update_neopixels(0, 0, 0, 0);
  }
}


void FlashingState::tick(uint32_t now)
{
  if (now >= step_time) {
    flash_state = !flash_state;
    update_fractional(red, green, blue, white);
    step_time = now + step_interval;
  }
}
