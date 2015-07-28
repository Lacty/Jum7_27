
#include "title.h"
#include "../scene_state.h"
#include "../Collision/collision.h"


// ïœêîÇÕÇ±Ç±Ç≈êÈåæ
namespace TitleVar {
  Texture bg;
  Texture image;
}

void titleSetup() {
  using namespace TitleVar;
  bg = Texture("res/sky.png");
  image = Texture("res/title.png");
}

void titleUpdate(AppEnv& env) {
  using namespace TitleVar;
  if (env.isPressKey('G')) {
    setSceneState(SceneState::GameMain);
  }
}

void titleDraw() {
  using namespace TitleVar;
  drawTextureBox(-512, -300, 1024, 600,
                 0, 0, 1024, 600, bg, Color(1, 1, 1));
  drawTextureBox(-512, -256, 1024, 512,
                 0, 0, 2048, 1024,
                 image, Color(1, 1, 1));
}
