#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	camera = window->getView();
	speed = 100;

	// initialise game objects
	playerTexture.loadFromFile("gfx/Mushroom.png");
	enemyOneTexture.loadFromFile("gfx/goomba.png");
	enemyTwoTexture.loadFromFile("gfx/Beach_Ball.png");
	cursorIcon.loadFromFile("gfx/icon.png");
	backgroundTexture.loadFromFile("gfx/Level1_1.png");

	// ----- Background -----
	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(11038, 675));
	background.setPosition(0, 0);
	background.setInput(input);

	// ----- Cursor -----
	cursor.setTexture(&cursorIcon);
	cursor.setSize(sf::Vector2f(20, 20));


	// ----- Player -----
	playerOne.setTexture(&playerTexture);
	playerOne.setSize(sf::Vector2f(100, 100));
	playerOne.setPosition(200, 200);
	playerOne.setInput(input);

	// ----- EnemyOne -----
	enemyOne.setTexture(&enemyOneTexture);
	enemyOne.setSize(sf::Vector2f(100, 100));
	enemyOne.setPosition(700, 700);
	enemyCentre.x = enemyOne.getSize().x / 2;
	enemyCentre.y = enemyOne.getSize().y / 2;
	enemyOne.setOrigin(enemyCentre);

	// ----- EnemyTwo -----
	enemyTwo.setTexture(&enemyTwoTexture);
	enemyTwo.setSize(sf::Vector2f(100, 100));
	enemyTwo.setPosition(340, 200);
	enemyCentre.x = enemyTwo.getSize().x / 2;
	enemyCentre.y = enemyTwo.getSize().y / 2;
	enemyTwo.setOrigin(enemyCentre);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	playerOne.handleInput(dt, speed);
}

// Update game objects
void Level::update(float dt)
{
	enemyOne.collision(window->getSize().x,window->getSize().y);
	enemyOne.movement(dt);
	enemyTwo.collision(window->getSize().x,window->getSize().y);
	enemyTwo.movement(dt);

	mousePos.x = input->getMouseX();
	mousePos.y = input->getMouseY();
	cursor.setPosition(mousePos);

	camera.setCenter(playerOne.getPosition());
	window->setView(camera);
}

// Render level
void Level::render()
{
	beginDraw();

	window->setMouseCursorVisible(false);
	window->draw(background);
	window->draw(testSprite);
	window->draw(playerOne);
	window->draw(enemyOne);
	window->draw(enemyTwo);
	window->draw(cursor);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}