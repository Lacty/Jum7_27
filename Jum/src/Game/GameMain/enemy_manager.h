#pragma once
#include "enemy.h"
#include  <List>

class Enemy_manager
{
public:
	void Setup();
	void Update();
  void Draw(float& camera_x);
	void Create(Enemy::PATERN type);

  // ���U���g�ɔ�ԑO�Ɏ��s�����邱��
  // Enemy�̏�񂪂��ׂď��������
  void clear();

private:

	std::list <Enemy> enemy;

};
