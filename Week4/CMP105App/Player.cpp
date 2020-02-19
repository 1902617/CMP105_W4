#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::handleInput(float dt, int speed)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(speed * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-speed * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		move(0, -speed * dt);
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		move(0, speed * dt);
	}
}