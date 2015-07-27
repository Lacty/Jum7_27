#pragma once
#include "enemy.h"
#include  <List>

class Enemy_manager
{
public:
	void Setup();
	void Update();
  void Draw(float& camera_x);
	void Create(Enemy::PATERN type);

  // リザルトに飛ぶ前に実行させること
  // Enemyの情報がすべて消去される
  void clear();

private:

	std::list <Enemy> enemy;

};
