#include "player.h"
#include "stage_state.h"


#define Init_Hp 2

Player::Player() {}

void Player::Gravity(AppEnv &env) {
  if (is_jump == false && env.isPushButton(Mouse::LEFT)) {
	  jump.play();
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
  jump = Media("res/jump.wav");
  bgm = Media("res/bgm.wav");
  bgm.play();
  bgm.looping(1);
  player_pos = Vec2f(Init_X, Init_Y);
  is_jump = false;
  time = 0;
  jump_powor = 20;
  gravity = 0.05f;
  is_collision_fence = false;
  HP = Init_Hp;
}

void Player::Update(AppEnv &env) {
  ++draw_time;
  if (draw_time > 20) {
    draw_time = 0;
  }
  if (is_collision_fence) {
    status = STATUS::INVINCIBLE;
    is_collision_fence = false;
    HP--;
    if (HP == 0) {
      status = DEAD;
    }
    player_pos.x() -= 50;
  }
  Gravity(env);
}

void Player::Draw(float& camera_x) {
  if (status == STATUS::INVINCIBLE) {
    if (draw_time < 6) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     0, 0, 257, 256, image, Color(1, 0, 0));
    }
    if (draw_time > 10 && draw_time < 16) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     514, 0, 257, 256, image, Color(1, 0, 0));
    }
    invincible_time++;
    if (invincible_time > 100) {
      invincible_time = 0;
      status = STATUS::ACTIVE;
    }
  } else 
  if (status == STATUS::ACTIVE) {
    if (draw_time < 6) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     0, 0, 257, 256, image, Color::white);
    }
    if (draw_time > 5 && draw_time < 11) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     257, 0, 257, 256, image, Color::white);
    }
    if (draw_time > 10 && draw_time < 16) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                    514, 0, 257, 256, image, Color::white);
    }
    if (draw_time > 15 && draw_time < 21) {
      drawTextureBox(player_pos.x() + camera_x, player_pos.y(), 120, 180,
                     771, 0, 257, 256, image, Color::white);
    }
  }
}