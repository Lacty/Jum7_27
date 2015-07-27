
#include "scene_state.h"
#include "game.h"


static SceneState state;

void setSceneState(const SceneState& _state) {
  state = _state;
  gameSetup();
}

const SceneState getSceneState() {
  return state;
}