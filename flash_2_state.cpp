// -*- mode: c++ -*-
// Flashing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "flash_2_state.h"

#define DEFAULT_STEP_INTERVAL (1000) // in milliseconds
#define STEP_DELTA (5)                // change in 50mS increments
#define MIN_STEP_INTERVAL (10)
#define MAX_STEP_INTERVAL (1000)

Flash2State::Flash2State(StateMachine *machine)
  : FlashingState(machine, "flash2", 5.0, DEFAULT_STEP_INTERVAL/2)
{
}


void Flash2State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  white = data[3];
  flash_state = true;
  update_fractional(red, green, blue, white);
}


void Flash2State::mode_button(void)
{
#if RGBW == 1
  go_to("white", cached_data);
#else
  go_to("static", cached_data);
#endif
}


// Flash faster
void Flash2State::red_button(void)
{
  step_interval -= STEP_DELTA;
  if (step_interval < MIN_STEP_INTERVAL) {
    step_interval = MIN_STEP_INTERVAL;
  }
}


// Reset breather rate
void Flash2State::green_button(void)
{
  step_interval = DEFAULT_STEP_INTERVAL;
}


// Flash slower
void Flash2State::blue_button(void)
{
  step_interval += STEP_DELTA;
  if (step_interval > MAX_STEP_INTERVAL) {
    step_interval = MAX_STEP_INTERVAL;
  }
}
