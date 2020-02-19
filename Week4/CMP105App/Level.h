#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Cursor.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	int speed;
	sf::Vector2f mousePos;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::View camera;


	// Level objects
	GameObject testSprite;
	sf::Texture playerTexture;
	sf::Texture enemyOneTexture;
	sf::Texture enemyTwoTexture;
	sf::Texture cursorIcon;
	sf::Texture backgroundTexture;

	Cursor cursor;
	Player playerOne;
	Enemy enemyOne;
	Enemy enemyTwo;
	Background background;
	sf::Vector2f enemyCentre;

};