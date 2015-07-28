#pragma once
#include  "../../lib/framework.hpp"
#include "gimic.h"
#include "player.h"
#include <List>


class Gimic_manager
{
public:
	void Setup();
	void Update(Player& player);
	void Draw();
	void Create(Gimic::PATERN type , int _x);

	// リザルトに飛ぶ前に実行させること
	// Enemyの情報がすべて消去される
	void clear();

private:

	std::list <Gimic> gimic;




};
