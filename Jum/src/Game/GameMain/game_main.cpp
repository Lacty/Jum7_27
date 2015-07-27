
#include "game_main.h"
#include "../scene_state.h"


// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace GameMainVar {
  int a;
}

void gameMainSetup() {
  using namespace GameMainVar;
  a = 0;
}

void gameMainUpdate(AppEnv& env) {
  using namespace GameMainVar;
  if (env.isPushKey('R')) {
    setSceneState(SceneState::Result);
  }
}

void gameMainDraw() {
  using namespace GameMainVar;
  drawFillCircle(0, 0, 50, 50, 3, Color(1 ,1, 1));
}