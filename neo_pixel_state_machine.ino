// -*- mode: c++ -*-
// Neopixel state machine example
//
// Copyright (c) 2021 Dave Astels

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
#include "state_machine.h"
#include "static_state.h"

const uint32_t tick_interval = 10; // mS
uint32_t tick_time = 0;

Bounce mode_button = Bounce();
Bounce red_button = Bounce();
Bounce green_button = Bounce();
Bounce blue_button = Bounce();
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 1, NEO_GRB + NEO_KHZ800);
StateMachine machine = StateMachine();

void setup()
{
  Serial.begin(9600);
  strip.begin();

  mode_button.attach (0, INPUT_PULLUP);
  mode_button.interval(5);
  red_button.attach (2, INPUT_PULLUP);
  red_button.interval(5);
  green_button.attach (3, INPUT_PULLUP);
  green_button.interval(5);
  blue_button.attach (4, INPUT_PULLUP);
  blue_button.interval(5);

  machine.add_state(new StaticState(&machine));
  // machine.add_state(new Breath1State("breath1"));
  // machine.add_state(new Breath2State("breath2"));
  // machine.add_state(new Flash1State("flash1"));
  // machine.add_state(new Flash2State("flash2"));
  machine.reset();
}


void loop()
{
  uint32_t now = millis();

  mode_button.update();
  red_button.update();
  green_button.update();
  blue_button.update();

  // generate time event when appropriate
  if (now >= tick_time) {
    machine.tick(now);
  }

  // generate button events when they are pressed
  if (mode_button.fell()) {
    machine.mode_button();
  } else if (red_button.fell()) {
    machine.red_button();
  } else if (green_button.fell()) {
    machine.green_button();
  } else if (blue_button.fell()) {
    machine.blue_button();
  }

}
