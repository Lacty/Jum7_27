#pragma once
#include  "../../lib/framework.hpp"
#include "../window_state.h"


class Stage {
public:
	Stage() : sky_pos(0,0) {}

	void Set_up();
	void Update() { sky_pos.x() += 16; }
	void Draw();

private:

	Vec2f sky_pos;
	Texture sky ;
};