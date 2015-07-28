#pragma once
#include  "../../lib/framework.hpp"

class Gimic {
public:
  enum PATERN {
    FIRE,
	POP_ZOMBIE,
    SIGNBORAD_YELLOW,
    SIGNBORAD_WHITE
  } patern;

  Gimic(PATERN patern , int _x);

  void Update();
  void Draw();
  
  Vec2f Get_pos() { return pos; }
  Vec2f Get_size() { return size; }

private:
  Vec2f pos;
  Vec2f size;
  PATERN type;
  Texture image;
  int draw_time;
  bool is_draw;
};