
#include "game_main.h"
#include "../scene_state.h"
#include "player.h"
#include "stage.h"
#include "enemy_manager.h"
#include "gimic.h"
#include "stage_state.h"

#include "../Collision/collision.h"

#define GimicNum 10

// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace GameMainVar 
{
  StageState state;
	Player player;
	Stage stage;
  // Gimic gimic[GimicNum];
	Enemy_manager manager;
}

void gameMainSetup() 
{
  using namespace GameMainVar;
  state.setup();
  stage.Set_up();
  /*for (int i = 0; i < GimicNum; ++i) {
    gimic[i].Setup(Vec2f(1000 + (i * 600), -300),
                   Vec2f(80, 80));
  }*/
  manager.Setup();
  player.Setup();
}

void gameMainUpdate(AppEnv& env) 
{
  using namespace GameMainVar;
  state.update();
  stage.Update();
  /*for (int i = 0; i < GimicNum; ++i) {
    gimic[i].Update();
  }*/
  manager.Update();
  player.Update(env);
  /*for (int i = 0; i < GimicNum; ++i) {
    if (isRectToRect(player.getPos().x(), player.getPos().y(),
                     player.getSize().x(), player.getSize().y(),
                     gimic[i].Get_pos().x(), gimic[i].Get_pos().y(),
                     gimic[i].Get_size().x(), gimic[i].Get_size().y()))
    {
      setSceneState(SceneState::Result);
    }
  }*/
}

void gameMainDraw()
{
  using namespace GameMainVar;
 
 
  stage.Draw();
  /*for (int i = 0; i < GimicNum; ++i) {
    gimic[i].Draw();
  }*/
  manager.Draw(state.camera_x);
  player.Draw(state.camera_x);
}