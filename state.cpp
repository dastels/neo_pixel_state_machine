// State base class
//
// Copyright (c) 2021 Dave Astels

#include <string.h>
#include "state.h"
#include "state_machine.h"

extern Adafruit_NeoPixel strip;

State::State(StateMachine *machine, char *name)
  : _machine(machine)
  , _name(name)
{
}


bool State::is_named(char *name)
{
  return strcmp(name, _name) == 0;
}


void State::go_to(char *state_name, uint8_t *data)
{
  _machine->go_to_state(state_name, data);
}

void State::update_neopixels(uint8_t red, uint8_t green, uint8_t blue,uint8_t white)
{
#if RGBW == 1
  strip.fill(strip.Color(red, green, blue, white));
#else
  strip.fill(strip.Color(red, green, blue));
#endif
  strip.show();
}

uint8_t State::next_value(uint8_t c)
{
  if (c == 255) {
    return 0;
  } else if (c >= 240) {
    return 255;
  } else {
    return c + 16;
  }
}

uint8_t State::middle_value(uint8_t c)
{
  return 127;
}

uint8_t State::previous_value(uint8_t c)
{
  if (c == 0) {
    return 255;
  } else if (c <= 15) {
    return 0;
  } else {
    return c - 16;
  }
}
