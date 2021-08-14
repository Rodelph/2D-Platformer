#include "prcHead.h"
#include "Game.h"

Game::Game() { this->initWindow(); }

Game::~Game() { delete this->player; }

void Game::initWindow() { this->window.create(sf::VideoMode(800, 600), "Platformer", sf::Style::Close | sf::Style::Titlebar); }

void Game::initPlayer() { this->player = new Player(); }

void Game::updatePlayer() { this->player->update(); }

void Game::renderPlayer(sf::RenderTarget& target)
{

}

void Game::update()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed) { this->window.close(); }
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) { this->window.close(); }
	}

	this->updatePlayer();
}

void Game::render() { this->window.clear(sf::Color(255, 255, 255, 255)); }

const sf::RenderWindow& Game::getWindow() const { return this->window; }