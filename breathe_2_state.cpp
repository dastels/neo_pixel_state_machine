// -*- mode: c++ -*-
// Breathing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "breathe_2_state.h"

#define DEFAULT_STEP_INTERVAL (50) // in milliseconds
#define STEP_DELTA (1)                // change in 50mS increments
#define MIN_STEP_INTERVAL (1)
#define MAX_STEP_INTERVAL (1000)

Breathe2State::Breathe2State(StateMachine *machine)
  : BreathingState(machine, "breathe2", 1.0, DEFAULT_STEP_INTERVAL)
{
}


void Breathe2State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  white = data[3];
  breathe_value = 100.0;
  update_fractional(red, green, blue, white);
}


void Breathe2State::mode_button(void)
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  cached_data[3] = white;
  go_to("flash1", cached_data);
}


// Breathe faster
void Breathe2State::red_button(void)
{
  step_interval -= STEP_DELTA;
  if (step_interval < MIN_STEP_INTERVAL) {
    step_interval = MIN_STEP_INTERVAL;
  }
}


// Reset breather rate
void Breathe2State::green_button(void)
{
  step_interval = DEFAULT_STEP_INTERVAL;
}


// Breathe slower
void Breathe2State::blue_button(void)
{
  step_interval += STEP_DELTA;
  if (step_interval > MAX_STEP_INTERVAL) {
    step_interval = MAX_STEP_INTERVAL;
  }
}
