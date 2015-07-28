#pragma once
#include  "../../lib/framework.hpp"
#include "../window_state.h"
#include "gimic.h"


class Player {
private:
  enum {
    Init_X = -200,
    Init_Y = GROUND_Y
  };

  Gimic::PATERN gimic_patern;
  bool is_collision_fence;
  int HP;

public:
  Player();

  enum STATUS {
    ACTIVE,
    INVINCIBLE,
    DEAD
  } status;

  void Setup();

  void Gravity(AppEnv &env);

  void Update(AppEnv &env);
  void Draw(float& camera_x);

  Vec2f getPos() { return player_pos; }
  Vec2f getSize() { return Vec2f(100, 150); }

  void collisionToGimic(Gimic::PATERN patern) {
    gimic_patern = patern;
    if (!status == STATUS::ACTIVE) return;
    if (gimic_patern == Gimic::SIGNBORAD_WHITE || gimic_patern == Gimic::SIGNBORAD_YELLOW) {
      is_collision_fence = true;
    }
    if (gimic_patern == Gimic::FIRE || gimic_patern == Gimic::PATERN::POP_ZOMBIE) {
      status = DEAD;
    }
  }

  Gimic::PATERN getCollisionGimic() {
    return this->gimic_patern;
  }

  bool isDead() {
    if (status == DEAD) {
      return true;
    }
    return false;
  }

private:

  Vec2f player_pos;
  Vec2f size;
  bool is_jump;
  float gravity;
  int time;
  int draw_time = 0;
  int jump_powor;
  Texture image;
  int invincible_time;
};

