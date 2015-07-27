
#include "result.h"
#include "../scene_state.h"


// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace ResultVar {
  int a;
}

void resultSetup() {
  using namespace ResultVar;
  a = 0;
}

void resultUpdate(AppEnv& env) {
  using namespace ResultVar;
  if (env.isPushKey('T')) {
    setSceneState(SceneState::Title);
  }
}

void resultDraw() {
  using namespace ResultVar;
  drawFillCircle(0, 0, 50, 50, 100, Color(1, 1, 1));
}