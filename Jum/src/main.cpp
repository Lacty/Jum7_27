
//
// ゲームジャム用のフレームワークです
// 1年生が使用することを想定して
// クラス不使用の簡易的なものにしました
// すべてのシーンが同時に存在しているので
// あまり巨大なリソース(画像.etc)は使用しないでください
//

#include "lib/framework.hpp"
#include "Game/game.h"
#include "Game/Scene_state.h"


int main() {
  AppEnv env(1024, 600);
  setSceneState(Title);

  while (env.isOpen()) {
    env.begin();

    gameRun(env);

    env.end();
  }
}
