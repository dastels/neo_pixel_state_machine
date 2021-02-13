// -*- mode: c++ -*-
// Breathing state with speed adjust
//
// Copyright (c) 2021 Dave Astels

#include "breathe_2_state.h"

#define DEFAULT_STEP_INTERVAL (100) // in milliseconds
#define STEP_DELTA (20)                // change in 50mS increments
#define MIN_STEP_INTERVAL (10)
#define MAX_STEP_INTERVAL (1000)

Breathe2State::Breathe2State(StateMachine *machine)
  : State(machine, "breathe2")
  , breathe_delta(5.0)          // changes of 5%
  , step_interval(DEFAULT_STEP_INTERVAL)
  , step_time(0)
{

}


void Breathe2State::enter(uint8_t *data)
{
  cached_data = data;
  red = data[0];
  green = data[1];
  blue = data[2];
  breathe_value = 100.0;
  update_fractional(red, green, blue);
}


uint8_t Breathe2State::compute_fractional(uint8_t colour)
{
  return (uint8_t)((float)colour * breathe_value / 100.0);
}

void Breathe2State::update_fractional(uint8_t r, uint8_t g, uint8_t b)
{
  update_neopixels(compute_fractional(r), compute_fractional(g), compute_fractional(b));
}


void Breathe2State::mode_button(void)
{
  go_to("static", cached_data);
}


void Breathe2State::red_button(void)
{
  step_interval -= STEP_DELTA;
  if (step_interval < MIN_STEP_INTERVAL) {
    step_interval = MIN_STEP_INTERVAL;
  }
}


void Breathe2State::green_button(void)
{
  step_interval = DEFAULT_STEP_INTERVAL;
}


void Breathe2State::blue_button(void)
{
  step_interval += STEP_DELTA;
  if (step_interval > MAX_STEP_INTERVAL) {
    step_interval = MAX_STEP_INTERVAL;
  }
}


void Breathe2State::tick(uint32_t now)
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
    update_fractional(red, green, blue);
    step_time = now + step_interval;
  }
}
