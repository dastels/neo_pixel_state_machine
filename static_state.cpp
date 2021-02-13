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
  update_neopixels(red, green, blue);
}


void StaticState::mode_button()
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  go_to("breathe1", cached_data);
}


uint8_t next_colour(uint8_t c)
{
  if (c == 255) {
    return 0;
  } else if (c == 240) {
    return 255;
  } else {
    return c + 16;
  }
}


void StaticState::red_button()
{
  red = next_colour(red);
  update_neopixels(red, green, blue);
}


void StaticState::green_button()
{
  green = next_colour(green);
  update_neopixels(red, green, blue);
}


void StaticState::blue_button()
{
  blue = next_colour(blue);
  update_neopixels(red, green, blue);
}
