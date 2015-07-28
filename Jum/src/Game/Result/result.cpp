
#include "result.h"
#include "../scene_state.h"
#include "../GameMain/gimic.h"
#include "../Collision/collision.h"
#include "getter.h"


enum Button {
  UnSelect,
  Selected
};

// ïœêîÇÕÇ±Ç±Ç≈êÈåæ
namespace ResultVar {
  Texture cutin;
  Texture bg;
  Texture player;
  Texture button_retry;
  Button retry;
  Texture button_title;
  Button title;

  Vec2f retry_pos;
  Vec2f title_pos;
}

void resultSetup() {
  using namespace ResultVar;
  bg = Texture("res/sky.png");
  cutin = Texture("res/cutin_fire.png");
  player = Texture("res/hagetaoreru.png");
  button_retry = Texture("res/button_retry.png");
  button_title = Texture("res/button_title.png");
  retry = UnSelect;
  title = UnSelect;

  retry_pos = Vec2f(150, -100);
  title_pos = Vec2f(-400, -100);
}

void resultUpdate(AppEnv& env) {
  using namespace ResultVar;
  Vec2f Button_Size = Vec2f(256, 128);

  if (isPointToRect(env.mousePosition().x(),
    env.mousePosition().y(),
    retry_pos.x(),
    retry_pos.y(),
    Button_Size.x(),
    Button_Size.y())) {
    retry = Selected;
    if (env.isPushButton(Mouse::LEFT)) {
      setSceneState(SceneState::GameMain);
    }
  } else { retry = UnSelect; }

  if (isPointToRect(env.mousePosition().x(),
    env.mousePosition().y(),
    title_pos.x(),
    title_pos.y(),
    Button_Size.x(),
    Button_Size.y())) {
    title = Selected;
    if (env.isPushButton(Mouse::LEFT)) {
      setSceneState(SceneState::Title);
    }
  } else { title = UnSelect; }

  if (env.isPushKey('T')) {
    setSceneState(SceneState::Title);
  }
}

void resultDraw() {
  using namespace ResultVar;
  if (Getter::get().patern == Gimic::FIRE) {
    drawTextureBox(-512, -300, 1024, 600,
                   0, 0, 1024, 600, bg, Color(1, 1, 1));
    drawTextureBox(-512, -256, 1024, 512,
                   0, 0, 1024, 512,
                   cutin, Color(1, 1, 1));
    drawTextureBox(-170, -430, 380, 250,
                   512, 180, 300, 200,
                   player, Color(1, 1, 1));

    drawTextureBox(title_pos.x(), title_pos.y(), 256, 128,
                   256 * title, 0, 256, 128,
                   button_title, Color(1, 1, 1));
    drawTextureBox(retry_pos.x(), retry_pos.y(), 256, 128,
                   256 * retry, 0, 256, 128,
                   button_retry, Color(1, 1, 1));
  }


}