// -*- mode: c++ -*-
// Breathing state with colour adjust
//
// Copyright (c) 2021 Dave Astels

#include "breathe_1_state.h"

#define DEFAULT_BREATH_TIME (5000) // in milliseconds

Breathe1State::Breathe1State(StateMachine *machine)
  : BreathingState(machine, "breathe1", 5.0, DEFAULT_BREATH_TIME / 100)
{
}


void Breathe1State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  white = data[3];
  breathe_value = 100.0;
  update_fractional(red, green, blue, white);
}


void Breathe1State::mode_button(void)
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  cached_data[3] = white;
  go_to("breathe2", cached_data);
}


void Breathe1State::red_button(void)
{
  red = next_colour(red);
  update_fractional(red, green, blue, white);
}


void Breathe1State::green_button(void)
{
  green = next_colour(green);
  update_fractional(red, green, blue, white);
}


void Breathe1State::blue_button(void)
{
  blue = next_colour(blue);
  update_fractional(red, green, blue, white);
}
