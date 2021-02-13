// -*- mode: c++ -*-
// Breathing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "breathing_state.h"

BreathingState::BreathingState(StateMachine *machine, char *name, float delta, int interval)
  : State(machine, name)
  , breathe_delta(delta)          // changes of 5%
  , step_interval(interval)
  , step_time(0)
{
}


uint8_t BreathingState::compute_fractional(uint8_t colour)
{
  return (uint8_t)((float)colour * breathe_value / 100.0);
}


void BreathingState::update_fractional(uint8_t r, uint8_t g, uint8_t b)
{
  update_neopixels(compute_fractional(r), compute_fractional(g), compute_fractional(b));
}


void BreathingState::tick(uint32_t now)
{
  if (now >= step_time) {
    breathe_value += breathe_delta;
    if (breathe_value > 100.0) {
      breathe_value = 100.0;
      breathe_delta *= -1;
    } else if (breathe_value <= 0.0) {
      breathe_value = 0.0;
      breathe_delta *= -1;
    }
    update_fractional(red, green, blue);
    step_time = now + step_interval;
  }
}
