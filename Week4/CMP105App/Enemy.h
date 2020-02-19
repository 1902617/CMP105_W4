#pragma once
#include "Framework/GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	int speedX, speedY;
	float dirX, dirY;

	void collision(int windowX, int windowY);
	void movement(float dt);
};
