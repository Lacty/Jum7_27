#include "gimic.h"
#include "../window_state.h"


Gimic::Gimic(PATERN patern , int _x) {
  this->patern = patern;
  switch (this->patern) {
  case Gimic::FIRE: 
  {
	  draw_time = 0;
	  image = Texture("res/fire.png");
	  pos = Vec2f(_x,GROUND_Y);
	  size = Vec2f(100, 130);
  } break;
  case Gimic::POP_ZOMBIE:

	  image = Texture("res/zombie_mh.png");
	  pos = Vec2f(_x, -280);
	  size = Vec2f(120, 80);
	  is_draw = false;
	 
	  break;
  case Gimic::SIGNBORAD_YELLOW: 
  {
	  image = Texture("res/signboard_yellow.png");
	  pos = Vec2f(_x, GROUND_Y);
	  size = Vec2f(130, 130);
  } break;
  case Gimic::SIGNBORAD_WHITE: {

  } break;

  default:
    break;
  }
}

void Gimic::Update() 
{
	++draw_time;
  pos.x() -= 12;
}



void Gimic::Draw() 
{
	switch (this->patern) 
	{

	case Gimic::FIRE: 
	{
		if (draw_time < 9)
		{
			drawTextureBox(pos.x() -50, pos.y(), size.x() + 80,size.y() + 50,
				0, 0, 256, 256, image, Color::white);
		}

		if (draw_time > 8 && draw_time < 17)
		{
			drawTextureBox(pos.x() -50, pos.y(), size.x() + 80,size.y() + 50,
				256, 0, 256, 256, image, Color::white);
		}
		if (draw_time > 15) 
		{ 
			draw_time = 0;
		}

	} break;

	case Gimic::POP_ZOMBIE:
	{
		if (pos.x() < 400)
		{
			
			is_draw = true;
		}
		if (!is_draw)
		{
			draw_time = 0;
		}

		if (is_draw){
			if (draw_time < 9)
			{
				drawTextureBox(pos.x() - 120, pos.y(), size.x() + 60, size.y() + 100,
					0, 0, 150, 256, image, Color::white);
			}

		 if (draw_time > 8 && draw_time < 17)
			{
				drawTextureBox(pos.x() - 120, pos.y(), size.x() + 60, size.y() + 100,
					150, 0, 150, 256, image, Color::white);
			}

			if (draw_time > 16 )
			{
				drawTextureBox(pos.x() - 120, pos.y(), size.x() + 60, size.y() + 60,
				300, 0, 150, 256, image, Color::white);
			}
		
		}

	}break;
	default: 
	{
		drawTextureBox(pos.x(), pos.y(), 180, 180,
			0, 0, 256, 256, image, Color::white);
	} break;
	}
 
}