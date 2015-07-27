#pragma once
#include  "../../lib/framework.hpp"
#include "../window_state.h"


class Player {
private:
  enum {
    Init_X = -200,
    Init_Y = GROUND_Y
  };

public:
  Player();

  enum STATUS {
    ACTIVE,
    INVINCIBLE,
    DEAD
  };

  void Setup();

  void Gravity(AppEnv &env);

  void Update(AppEnv &env);
  void Draw(float& camera_x);

  Vec2f getPos() { return player_pos; }
  Vec2f getSize() { return Vec2f(100, 150); }

private:

  Vec2f player_pos;
  Vec2f size;
  bool is_jump;
  float gravity;
  int time;
  int draw_time = 0;
  int jump_powor;
  Texture image;
  STATUS status;
};

