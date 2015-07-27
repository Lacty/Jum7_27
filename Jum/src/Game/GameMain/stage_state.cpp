
#include "stage_state.h"


void StageState::setup() {
  stage_state = Start;
  camera_speed = 2;
  camera_x = 500;
}

void StageState::update() {
  if (camera_x > 0) {
    camera_x -= camera_speed;
  } else {
    stage_state = Play;
  }
}