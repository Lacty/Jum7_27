
#include "result.h"
#include "../scene_state.h"


// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace ResultVar {
  Texture cutin;
  Texture bg;
}

void resultSetup() {
  using namespace ResultVar;
  bg = Texture("res/sky.png");
  cutin = Texture("res/cutin_fire.png");
}

void resultUpdate(AppEnv& env) {
  using namespace ResultVar;
  if (env.isPushKey('T')) {
    setSceneState(SceneState::Title);
  }
}

void resultDraw() {
  using namespace ResultVar;
  drawTextureBox(-512, -300, 1024, 600,
                 0, 0, 1024, 600, bg, Color(1, 1, 1));
  drawTextureBox(-512, -256, 1024, 512,
                 0, 0, 1024, 512,
                 cutin, Color(1, 1, 1));
  Font font("res/rounded-mplus-1c-black.ttf");
  font.size(60);
  font.draw("ƒŠƒUƒ‹ƒg", Vec2f(-100, 200), Color(1, 1, 1));
}