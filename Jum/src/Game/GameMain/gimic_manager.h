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

	// ���U���g�ɔ�ԑO�Ɏ��s�����邱��
	// Enemy�̏�񂪂��ׂď��������
	void clear();

private:

	std::list <Gimic> gimic;




};
