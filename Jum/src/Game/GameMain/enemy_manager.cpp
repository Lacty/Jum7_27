#include "enemy_manager.h"


void Enemy_manager::Create(Enemy::PATERN type) {
  enemy.push_back(type);
}


void Enemy_manager::Setup() {
  for (int i = 0; i < 10; ++i) {
    Create(Enemy::PATERN::RUN_TYPE);
  }
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