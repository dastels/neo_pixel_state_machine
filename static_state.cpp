// -*- mode: c++ -*-
// Static colour state
//
// Copyright (c) 2021 Dave Astels

#include "static_state.h"

StaticState::StaticState(StateMachine *machine)
  : State(machine, "static")
{
}


void StaticState::enter(void *data)
{
  red = 0;
  green = 0;
  blue = 0;
  update_neopixels(red, green, blue);
}


void StaticState::mode_button()
{
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
