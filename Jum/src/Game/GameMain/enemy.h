#pragma once
#include  "../../lib/framework.hpp"

class Enemy {
public:
  enum PATERN {
    RUN_TYPE,
    POP_TYPE,
    FALL_TYPE,
    FORMAL_TYPE
  };

  Enemy(PATERN type , int _x);

  void Update();
  void Draw(float& camera_x);
  
  Vec2f Get_pos() { return pos; }
  Vec2f Get_size() { return size; }

private:
  Vec2f pos;
  Vec2f size;
  PATERN type;
  Texture image;
  int draw_time = 0;


};