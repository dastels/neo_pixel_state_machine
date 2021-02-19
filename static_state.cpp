// -*- mode: c++ -*-
// Static colour state
//
// Copyright (c) 2021 Dave Astels

#include "static_state.h"

StaticState::StaticState(StateMachine *machine)
  : State(machine, "static")
{
}


void StaticState::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  white = data[3];
  update_neopixels(red, green, blue, white);
}


void StaticState::mode_button()
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  cached_data[3] = white;
  go_to("breathe1", cached_data);
}


// Change red value
void StaticState::red_button()
{
  red = next_value(red);
  update_neopixels(red, green, blue, white);
}


// Change green value
void StaticState::green_button()
{
  green = next_value(green);
  update_neopixels(red, green, blue, white);
}


// Change blue value
void StaticState::blue_button()
{
  blue = next_value(blue);
  update_neopixels(red, green, blue, white);
}
