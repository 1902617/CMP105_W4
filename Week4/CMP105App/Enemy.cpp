#include "Enemy.h"

Enemy::Enemy()
{
	speedX = 50;
	speedY = 25;
	dirX = true;
	dirY = true;
}

Enemy::~Enemy()
{
}

void Enemy::collision(int windowX, int windowY)
{
	if (getPosition().x >= (windowX-50))
	{
		dirX = false;
	}

	if (getPosition().x <= 50)
	{
		dirX = true;
	}

	if (getPosition().y >= (windowY-50))
	{
		dirY = false;
	}
	
	if (getPosition().y <= 50)
	{
		dirY = true;
	}
}

void Enemy::movement(float dt)
{
	if (dirX)
	{
		move(speedX * dt, 0);
	}
	else if (!dirX)
	{
		move(-speedX * dt, 0);
	}
	if (dirY)
	{
		move(0, speedY * dt);
	}
	if (!dirY)
	{
		move(0, -speedY * dt);
	}
}