
#include "result.h"
#include "../scene_state.h"
#include "../GameMain/gimic.h"
#include "../Collision/collision.h"
#include "getter.h"


enum Button {
  UnSelect,
  Selected
};

// 変数はここで宣言
namespace ResultVar {
  Texture cutin1;
  Texture cutin2;
  Texture bg;
  Texture player;
  Texture button_retry;
  Button retry;
  Texture button_title;
  Button title;

  Texture clear;

  Vec2f retry_pos;
  Vec2f title_pos;
}

void resultSetup() {
  using namespace ResultVar;
  bg = Texture("res/sky.png");
  cutin1 = Texture("res/cutin_fire.png");
  cutin2 = Texture("res/cutin_zombie.png");
  player = Texture("res/hagetaoreru.png");
  button_retry = Texture("res/button_retry.png");
  button_title = Texture("res/button_title.png");
  clear = Texture("res/clear.png");

  retry = UnSelect;
  title = UnSelect;

  retry_pos = Vec2f(150, -180);
  title_pos = Vec2f(-400, -180);
}

void resultUpdate(AppEnv& env) {
  using namespace ResultVar;
  Vec2f Button_Size = Vec2f(256, 128);

  if (!Getter::get().isClear) {
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
  }

  if (env.isPushButton(Mouse::LEFT)) {
    setSceneState(SceneState::Title);
  }
}

void resultDraw() {
  using namespace ResultVar;
  drawTextureBox(-512, -300, 1024, 600,
                 0, 0, 1024, 600, bg, Color(1, 1, 1));

  if (Getter::get().isClear) {
    drawTextureBox(-clear.width() / 2, -clear.height() / 2,
                   clear.width(), clear.height(),
                   0, 0, clear.width(), clear.height(),
                   clear, Color(1, 1, 1));
  } else 
  if (Getter::get().patern == Gimic::FIRE) {
    drawTextureBox(-512, -200, 1024, 512,
                   0, 0, 1024, 512,
                   cutin1, Color(1, 1, 1));
    drawTextureBox(-170, -430, 380, 250,
                   512, 180, 300, 200,
                   player, Color(1, 1, 1));
    drawTextureBox(title_pos.x(), title_pos.y(), 256, 128,
                   256 * title, 0, 256, 128,
                   button_title, Color(1, 1, 1));
    drawTextureBox(retry_pos.x(), retry_pos.y(), 256, 128,
                   256 * retry, 0, 256, 128,
                   button_retry, Color(1, 1, 1));
  } else {
    drawTextureBox(-512, -200, 1024, 512,
                   0, 0, 1024, 512,
                   cutin2, Color(1, 1, 1));
    drawTextureBox(title_pos.x(), title_pos.y(), 256, 128,
                   256 * title, 0, 256, 128,
                   button_title, Color(1, 1, 1));
    drawTextureBox(retry_pos.x(), retry_pos.y(), 256, 128,
                   256 * retry, 0, 256, 128,
                   button_retry, Color(1, 1, 1));
  }
}