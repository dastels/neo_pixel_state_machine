// -*- mode: c++ -*-
// All white colour state
//
// Copyright (c) 2021 Dave Astels
// Revision to add white state by Rob Mohr

#include "white_state.h"

WhiteState::WhiteState(StateMachine *machine)
  : State(machine, "white")
{
}


void WhiteState::enter(uint8_t *data)
{
  cached_data = data;
  red = 0;
  green = 0;
  blue = 0;
  white = data[3];
  update_neopixels(red, green, blue, white);
}

void WhiteState::mode_button()
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  cached_data[3] = white;
  go_to("static", cached_data);
}


void WhiteState::red_button()
{
  white = next_value(white);
  update_neopixels(red, green, blue, white);
}


void WhiteState::green_button()
{
  white = 127;
  update_neopixels(red, green, blue, white);
}


void WhiteState::blue_button()
{
  white = previous_value(white);
  update_neopixels(red, green, blue, white);
}
