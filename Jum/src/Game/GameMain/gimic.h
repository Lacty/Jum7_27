#pragma once
#include  "../../lib/framework.hpp"

class Gimic {
public:
  enum PATERN {
    FIRE,
    SIGNBORAD_YELLOW,
    SIGNBORAD_WHITE
  } patern;

  Gimic(PATERN patern);

  void Setup(const Vec2f& pos,
             const Vec2f& size);
  void Update();
  void Draw();

  Vec2f Get_pos() { return pos; }
  Vec2f Get_size() { return size; }

private:
  Vec2f pos;
  Vec2f size;
  PATERN type;
  Texture image;
};