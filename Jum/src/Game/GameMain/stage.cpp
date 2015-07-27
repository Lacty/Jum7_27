#include "stage.h"


void Stage::Set_up() {
  sky = Texture("res/sky.png");
}

void Stage::Draw() {
  drawTextureBox(EDGE_LEFT, EDGE_DOWN, Width, Height,
                 sky_pos.x(), sky_pos.y(), Height * 2 - 201, 600, sky, Color::white);

}