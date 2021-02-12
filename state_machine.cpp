// -*- mode: c++ -*-
// State Machine
//
// Copyright (c) 2021 Dave Astels
#include <string.h>
#include <Arduino.h>
#include "state_machine.h"


StateMachine::StateMachine()
  : _current_state(NULL)
  , _initial_state_name(nullptr)
  , _number_of_states(0)
{
}


bool StateMachine::add_state(State *state)
{
  if (_number_of_states == MAX_STATES) {
    Serial.print("Adding state ");
    Serial.print(state->name());
    Serial.println(" failed");
    return false;
  }
  _states[_number_of_states++] = state;
  if (!_initial_state_name) {
    _initial_state_name = state->name();
  }
  return true;
}


bool StateMachine::reset()
{
  if (go_to_state(_initial_state_name)) {
    return true;
  }
  Serial.print("Resetting to ");
  Serial.print(_initial_state_name);
  Serial.println(" failed!");
  return false;
}


State *StateMachine::find_state(char *state_name)
{
  for (int index = 0; index < _number_of_states; index++) {
    if (_states[index]->is_named(state_name)) {
      return _states[index];
    }
  }
  return nullptr;
}


bool StateMachine::go_to_state(char *state_name, void *data)
{
  if (!state_name || !*state_name) { // no state name
    Serial.println("No state name to go to");
    return false;
  }
  State *new_state = find_state(state_name);
  if (new_state == nullptr) {   // bad state name
    Serial.print("No state named ");
    Serial.println(state_name);
    return false;
  }
  if (_current_state) {
    _current_state->exit();
  }
  _current_state = new_state;
  _current_state->enter(data);
  return true;
}


void StateMachine::tick(uint32_t now)
{
  if (_current_state) {
    _current_state->tick(now);
  }
}


void StateMachine::mode_button()
{
  if (_current_state) {
    _current_state->mode_button();
  }
}


void StateMachine::red_button()
{
  if (_current_state) {
    _current_state->red_button();
  }
}


void StateMachine::green_button()
{
  if (_current_state) {
    _current_state->green_button();
  }
}


void StateMachine::blue_button()
{
  if (_current_state) {
    _current_state->blue_button();
  }
}


const char *StateMachine::current_state_name()
{
  if (_current_state) {
    return _current_state->name();
  } else {
    return "NOT_SET";
  }
}
