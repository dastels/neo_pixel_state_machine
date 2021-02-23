// -*- mode: c++ -*-
// Flashing state with colour adjust
//
// Copyright (c) 2021 Dave Astels

#include "flash_1_state.h"

#define DEFAULT_FLASH_TIME (1000) // in milliseconds


Flash1State::Flash1State(StateMachine *machine)
  : FlashingState(machine, "flash1", 5.0, DEFAULT_FLASH_TIME / 2)
{
}


void Flash1State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  white = data[3];
  flash_state = true;
  update_fractional(red, green, blue, white);
}


void Flash1State::mode_button(void)
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  cached_data[3] = white;
  go_to("flash2", cached_data);
}


// Change red value
void Flash1State::red_button(void)
{
  red = next_value(red);
  update_fractional(red, green, blue, white);
}


// Change green value
void Flash1State::green_button(void)
{
  green = next_value(green);
  update_fractional(red, green, blue, white);
}


// Change blue value
void Flash1State::blue_button(void)
{
  blue = next_value(blue);
  update_fractional(red, green, blue, white);
}
