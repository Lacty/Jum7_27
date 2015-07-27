
#include "game.h"
#include "scene_state.h"
#include "Title/title.h"
#include "GameMain/game_main.h"
#include "Result/result.h"


void gameRun(AppEnv& env) {
  gameUpdate(env);
  gameDraw();
}

void gameSetup() {
  switch (getSceneState()) {
  case Title: {
    titleSetup();
  } break;

  case GameMain: {
    gameMainSetup();
  } break;

  case Result: {
    resultSetup();
  } break;
  }
}

void gameUpdate(AppEnv& env) {
  switch (getSceneState()) {
  case Title: {
    titleUpdate(env);
  } break;

  case GameMain: {
    gameMainUpdate(env);
  } break;

  case Result: {
    resultUpdate(env);
  } break;
  }
}

void gameDraw() {
  switch (getSceneState()) {
  case Title: {
    titleDraw();
  } break;

  case GameMain: {
    gameMainDraw();
  } break;

  case Result: {
    resultDraw();
  } break;
  }
}