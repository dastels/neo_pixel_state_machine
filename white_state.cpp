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


uint8_t next_intensity(uint8_t c)
{
  if (c == 255) {
    return 0;
  } else if (c == 240) {
    return 255;
  } else {
    return c + 16;
  }
}

uint8_t middle_intensity(uint8_t c)
{
  return 127;
}

uint8_t previous_intensity(uint8_t c)
{
  if (c == 0) {
    return 255;
  } else if (c == 15) {
    return 0;
  } else {
    return c - 16;
  }
}
void WhiteState::red_button()
{
  white = next_intensity(white);
  update_neopixels(red, green, blue, white);
}


void WhiteState::green_button()
{
  white = middle_intensity(white);
  update_neopixels(red, green, blue, white);
}


void WhiteState::blue_button()
{
  white = previous_intensity(white);
  update_neopixels(red, green, blue, white);
}
