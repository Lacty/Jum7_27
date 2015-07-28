#include "enemy_manager.h"


void Enemy_manager::Create(Enemy::PATERN type ,int _x) {
	enemy.push_back({ type, _x });
}


void Enemy_manager::Setup() {

	Create(Enemy::PATERN::RUN_TYPE, -460);
	Create(Enemy::PATERN::RUN_TYPE, -450);
	Create(Enemy::PATERN::RUN_TYPE, -400);
}

void Enemy_manager::Update() {
  for (auto &it : enemy) {
    it.Update();
  }
}

void Enemy_manager::Draw(float& camera_x) {
  for (auto &it : enemy) {
    it.Draw(camera_x);
  }
}

void Enemy_manager::clear() {
  enemy.clear();
}