#include "prcHead.h"
#include "Game.h"

const sf::RenderWindow& Game::getWindow() const { return this->window; }

Game::Game() { this->initWindow(); this->initPlayer(); }

Game::~Game() { delete this->player; }

//
// Initializing the game
//

void Game::initWindow() { this->window.create(sf::VideoMode(1366, 720), "Platformer", sf::Style::Close | sf::Style::Titlebar); this->window.setFramerateLimit(60); }

void Game::initPlayer() { this->player = new Player(); }

//
// Updating the game
//

void Game::updateCollision()
{
	//Collision of the player with the bottom
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
	}
}

void Game::updatePlayer() { this->player->update(); }

void Game::update()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed) { this->window.close(); }
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) { this->window.close(); }

		if (this->ev.type == sf::Event::KeyReleased && 
			   ( this->ev.key.code == sf::Keyboard::Z || 
				 this->ev.key.code == sf::Keyboard::Q ||
				 this->ev.key.code == sf::Keyboard::S || 
				 this->ev.key.code == sf::Keyboard::D )) 
			{ this->player->resetAnimationTimer(); }
	}

	this->updatePlayer();
	this->updateCollision();
}

/// 
/// Rendering the game
/// 

void Game::renderPlayer() { this->player->render(this->window); }

void Game::render() 
{ 
	this->window.clear(sf::Color(255, 255, 255, 255)); 
	this->renderPlayer();
	this->window.display();
}