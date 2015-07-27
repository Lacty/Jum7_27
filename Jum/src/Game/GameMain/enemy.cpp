#include "enemy.h"
#include "../window_state.h"


// �ʒu������������Ƃ��͂����ɒǉ����邱��
enum EnemyInit {
  RunTypeX = EDGE_LEFT + 100,
};

Enemy::Enemy(PATERN type) {
  this->type = type;


  switch (type) {
  case RUN_TYPE: {

    pos = Vec2f(RunTypeX, GROUND_Y);
    size = Vec2f(256, 256);
    image = Texture("res/zombie_fm.png");

  }break;

  case POP_TYPE: {

  } break;

  case FALL_TYPE: {

  } break;

  case FORMAL_TYPE: {

  } break;
  }
}


void Enemy::Update() {
  switch (type) {
  case RUN_TYPE: {
    ++draw_time;

    if (draw_time > 16) {
      draw_time = 0;
    }
  } break;
  case POP_TYPE: {

  } break;
  case FALL_TYPE: {

  }break;
  case FORMAL_TYPE: {

  }break;

  }
}

void Enemy::Draw(float& camera_x) {
  switch (type) {
  case RUN_TYPE:

    if (draw_time < 6) {
      drawTextureBox(pos.x() + camera_x, pos.y(), size.x() / 4 * 3, size.y() / 4 * 3,
                     0, 0, 180, 256, image, Color::white);
    }

    if (draw_time > 5 && draw_time < 11) {
      drawTextureBox(pos.x() + camera_x, pos.y(), 200 / 4 * 3, size.y() / 4 * 3,
                     180, 0, 130, 256, image, Color::white);
    }
    if (draw_time > 10 && draw_time < 16) {
      drawTextureBox(pos.x() + camera_x, pos.y(), size.x() / 4 * 3, size.y() / 4 * 3,
                     360, 0, 150, 256, image, Color::white);
    }

    break;
  case POP_TYPE:

  case FALL_TYPE:

  case FORMAL_TYPE:
    break;
  }
}