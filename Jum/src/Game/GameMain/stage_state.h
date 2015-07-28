
#pragma once

class StageState {
public:
  enum State {
    Start,
    Play,
    Clear,
    Dead
  };

  State stage_state;
  float camera_x;
  float camera_speed;

  void setup();

  void update();
};