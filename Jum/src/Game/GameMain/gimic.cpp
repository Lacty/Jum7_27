#include "gimic.h"
#include "../window_state.h"


Gimic::Gimic(PATERN patern) {
  this->patern = patern;
  switch (this->patern) {
  case Gimic::FIRE: {

  } break;
  case Gimic::SIGNBORAD_YELLOW: {

  } break;
  case Gimic::SIGNBORAD_WHITE: {

  } break;

  default:
    break;
  }
}

void Gimic::Setup(const Vec2f& pos,
                  const Vec2f& size) {
  image = Texture("res/signboard_yellow.png");
  this->pos = pos;
  this->size = size;
}


void Gimic::Update() {
  pos.x() -= 12;
}



void Gimic::Draw() {
  drawTextureBox(pos.x(), pos.y(), 180, 180,
                 0, 0, 256, 256, image, Color::white);
}