
#pragma once


enum SceneState {
  Title,
  GameMain,
  Result
};

void setSceneState(const SceneState& _state);

const SceneState getSceneState();