#include "player.h"
#include "stage_state.h"


Player::Player() {}

void Player::Gravity(AppEnv &env) {
  if (is_jump == false && env.isPushButton(Mouse::LEFT)) {
    is_jump = true;
  }

  if (is_jump) {
    ++time;
    player_pos.y() += jump_powor - gravity * time * time;
  }

  if (player_pos.y() < GROUND_Y) {
    is_jump = false;
    player_pos.y() = GROUND_Y;
    time = 0;
  }
}

void Player::Setup() {
  status = STATUS::ACTIVE;
  image = Texture("res/hagerunjump.png");

  player_pos = Vec2f(Init_X, Init_Y);
  is_jump = false;
  time = 0;
  jump_powor = 20;
  gravity = 0.05f;
}

void Player::Update(AppEnv &env) {
  ++draw_time;
  if (draw_time > 20) {
    draw_time = 0;
  }

  Gravity(env);
}

void Player::Draw(float& camera_x) {
  if (status == STATUS::ACTIVE) {
    if (draw_time < 6) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     0, 0, 150, 256, image, Color::white);
    }
    if (draw_time > 5 && draw_time < 11) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 100, 180,
                     150, 0, 120, 256, image, Color::white);
    }
    if (draw_time > 10 && draw_time < 16) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 170,
                     270, 0, 160, 256, image, Color::white);
    }
    if (draw_time > 15 && draw_time < 21) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 170,
                     410, 0, 140, 256, image, Color::white);
    }
  }
}