
#include "game_main.h"
#include "../scene_state.h"
#include "player.h"
#include "stage.h"
#include "enemy_manager.h"
#include "gimic.h"
#include "gimic_manager.h"
#include "stage_state.h"

#include "../Collision/collision.h"

#define GimicNum 10

// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace GameMainVar
{
  StageState state;
  Player player;
  Stage stage;
  Enemy_manager enemy_manager;
  Gimic_manager gimic_manager;
}

void gameMainSetup() {
  using namespace GameMainVar;
  enemy_manager.clear();
  gimic_manager.clear();

  state.setup();
  stage.Set_up();
  enemy_manager.Setup();
  gimic_manager.Setup();

  player.Setup();
}

void gameMainUpdate(AppEnv& env) {
  using namespace GameMainVar;
  state.update();
  stage.Update();
  enemy_manager.Update();
  gimic_manager.Update(player);
  player.Update(env);
}

void gameMainDraw() {
  using namespace GameMainVar;

  stage.Draw();
  gimic_manager.Draw();
  enemy_manager.Draw(state.camera_x);
  player.Draw(state.camera_x);

  if (player.isDead()) {
    setSceneState(SceneState::Result);
  }
}