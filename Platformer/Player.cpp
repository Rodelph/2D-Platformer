#include "prcHead.h"
#include "Player.h"

void Player::initSprite()
{

}

void Player::initTexture()
{

}

Player::Player() { this->initTexture(); this->initSprite(); }

Player::~Player()
{
	
}

void Player::update()
{

}

void Player::render(sf::RenderTarget &target) { target.draw(this->sprite); }