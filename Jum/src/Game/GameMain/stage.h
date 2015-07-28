#pragma once
#include  "../../lib/framework.hpp"
#include "../window_state.h"
#include <memory>


#define Build_Num 6

class Stage {
public:
	Stage() : sky_pos(0,0) {}

	void Set_up();
	void Update(); 
	void Draw();

private:

	Vec2f sky_pos;
	Texture sky ;
	Texture build;
	Texture helicopter;
  int build_x[Build_Num];
	int time;
	int heli_pos_x;
	float heli_time;
  float comment_x;
};