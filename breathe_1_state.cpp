// -*- mode: c++ -*-
// Breate 1 state
//
// Copyright (c) 2021 Dave Astels

#include "breathe_1_state.h"

const int default_breath_time = 5000; // in milliseconds
void* cached_data;

Breathe1State::Breathe1State(StateMachine *machine)
  : State(machine, "breathe1")
  , breathe_delta(5.0)          // changes of 5%
  , step_interval(default_breath_time / 100)
  , step_time(0)
{

}


void Breathe1State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  update_neopixels(red, green, blue);
  breathe_value = 100.0;
}


uint8_t Breathe1State::compute_fractional(uint8_t colour)
{
  return (uint8_t)((float)colour * breathe_value / 100.0);
}

void Breathe1State::update_fractional(uint8_t r, uint8_t g, uint8_t b)
{
  update_neopixels(compute_fractional(r), compute_fractional(g), compute_fractional(b));
}


void Breathe1State::mode_button(void)
{
  cached_data[0] = red;
  cached_data[1] = green;
  cached_data[2] = blue;
  go_to("static", cached_data);
}


void Breathe1State::red_button(void)
{
  red = next_colour(red);
  update_fractional(red, green, blue);
}


void Breathe1State::green_button(void)
{
  green = next_colour(green);
  update_fractional(red, green, blue);
}


void Breathe1State::blue_button(void)
{
  blue = next_colour(blue);
  update_fractional(red, green, blue);
}


void Breathe1State::tick(uint32_t now)
{
  if (now >= step_time) {
    breathe_value += breathe_delta;
    if (breathe_value > 100.0) {
      breathe_value = 100.0;
      breathe_delta *= -1;
    } else if (breathe_value <= 0.0) {
      breathe_value = 0.0;
      breathe_delta *= -1;
    }
    update_neopixels(compute_fractional(red), compute_fractional(green), compute_fractional(blue));
    step_time = now + step_interval;
  }
}
