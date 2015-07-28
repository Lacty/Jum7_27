#include "stage.h"


void Stage::Set_up() 
{
  sky = Texture("res/sky.png");
  build = Texture("res/build.png");
  helicopter = Texture("res/helicopter.png");
  time = 100 * 60;
  heli_pos_x = -1300;
  heli_time = 0;
  build_x[0] = -200;
  build_x[1] = 0;
  build_x[2] = 300;
  build_x[3] = 500;
  build_x[4] = 700;
  build_x[5] = 900;

  comment_x = 0;
}


void Stage::Update()
{
  const int scroll_speed = 12;
	--time;
	sky_pos.x() += scroll_speed;
	heli_pos_x += 5;

	if (heli_pos_x > 1200)
	{
		heli_pos_x = -1200;
	}

	heli_time += 0.1f;
  for (int i = 0; i < Build_Num; ++i)
	{
		build_x[i] -= 3;
		if (build_x[i] < -1400)
		{
			build_x[i] = 600;
		}
	}
  comment_x += 5.f;
}

void Stage::Draw() {
	drawTextureBox(EDGE_LEFT, EDGE_DOWN, Width, Height,
                 sky_pos.x(), sky_pos.y(), Height * 2 - 201, 600, sky, Color::white);
  

	drawTextureBox(build_x[0], -258, 300, 450, 0, 0, 300, 512, build, Color::white);

	drawTextureBox(build_x[1], -258, 200, 300, 300, 0, 300, 512, build, Color::white);

	drawTextureBox(build_x[2] + 600, -258, 280, 400, 700, 0, 300, 512, build, Color::white);

	drawTextureBox(build_x[3], -258, 200, 300,
                 300, 0, 300, 512, build, Color::white);
  
  drawTextureBox(build_x[4] + 600, -258, 280, 400,
                 300, 0, 300, 512, build, Color::white);
  
  drawTextureBox(build_x[5] + 600, -258, 280, 400,
                 700, 0, 300, 512, build, Color::white);
  drawTextureBox(heli_pos_x, 160 + sin(heli_time) * 40, 140, 140, 
	                    0, 0, 512, 256, helicopter, Color::white);


  Font font("res/meiryo.ttc");
  font.size(50);
  font.draw("朝まで", Vec2f(0, 200), Color::red);
  std::string clear_time = std::to_string(time / 600);
  font.size(90);
  font.draw(clear_time, Vec2f(160, 200), Color::purple);
  font.size(50);
  font.draw("時間 ! !", Vec2f(230, 200), Color::red);

  font.size(100);
  font.draw("飲む前までは普通だったのになんでゾンビに！", Vec2f(-comment_x, 0), Color(1, 1, 1));
  const int offset = 2300;
  font.draw("に、逃げなきゃ！", Vec2f(-comment_x + offset, 0), Color(1, 1, 1));
}