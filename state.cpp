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


void State::go_to(char *state_name, void *data)
{
  _machine->go_to_state(state_name, data);
}

void State::update_neopixels(uint8_t red, uint8_t green, uint8_t blue)
{
  strip.fill(strip.Color(red, green, blue));
  strip.show();
}
