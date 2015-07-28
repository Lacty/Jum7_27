
#include "title.h"
#include "../scene_state.h"
#include "../Collision/collision.h"


// 変数はここで宣言
namespace TitleVar {
  Texture bg;
  Texture image;
  Texture player;
}

void titleSetup() {
  using namespace TitleVar;
  bg = Texture("res/sky.png");
  image = Texture("res/title.png");
}

void titleUpdate(AppEnv& env) {
  using namespace TitleVar;
  if (env.isPushButton(Mouse::LEFT)) {
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

  Font font("res/meiryo.ttc");
  const Vec2f pos = Vec2f(-200, -220);
  font.size(40);
  font.draw("クリックしたらスタート！", pos, Color(1, 1, 1));
}
