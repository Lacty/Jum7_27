
#pragma once
#include "../../lib/framework.hpp"


// データを初期化する場所
void gameMainSetup();

// 処理を行う場所
void gameMainUpdate(AppEnv& env);

// 描画を行う場所
void gameMainDraw();