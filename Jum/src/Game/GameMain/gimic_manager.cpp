#include "gimic_manager.h"
#include "../Collision/collision.h"


void Gimic_manager::Create(Gimic::PATERN type, int _x) {
  gimic.push_back({ type, _x });
}


void Gimic_manager::Setup() {


  Create(Gimic::PATERN::POP_ZOMBIE, 7000);
  Create(Gimic::PATERN::SIGNBORAD_YELLOW, 8000);
  Create(Gimic::PATERN::FIRE, 8700);

  Create(Gimic::PATERN::FIRE, 9300);
  Create(Gimic::PATERN::POP_ZOMBIE, 10500);
  Create(Gimic::PATERN::SIGNBORAD_YELLOW, 11100);
  Create(Gimic::PATERN::SIGNBORAD_YELLOW, 12100);




}

void Gimic_manager::Update(Player& player) {
  // 使用している画像に余白があるので
  // あたり判定でサイズを縮小させる
  const float scale = 0.8f;

  for (auto &it : gimic) {
    it.Update();
    if (isRectToRect(it.Get_pos().x(), it.Get_pos().y(),
      it.Get_size().x() * scale, it.Get_size().y() * scale,
      player.getPos().x(), player.getPos().y(),
      player.getSize().x() * scale, player.getSize().y() * scale)) {
      player.collisionToGimic(it.patern);
    }
  }
}

void Gimic_manager::Draw() {
  for (auto &it : gimic) {
    it.Draw();
  }
}

void Gimic_manager::clear() {
  gimic.clear();
}