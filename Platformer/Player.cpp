#include "prcHead.h"
#include "Player.h"

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50);
	this->sprite.setTextureRect(currentFrame);
	this->sprite.setScale(2.f, 2.f);
}

void Player::initTexture() { if (!this->textureSheet.loadFromFile(IOFile::getPlayerSheetDir())) std::cout << IOFile::getPlayerSheetError() << "\n"; }

void Player::initAnimations()
{
	this->clock.restart();
	this->animeSwitch = true;
}

void Player::initVariables()
{
	this->animeState = PLAYER_ANIMATION_STATES::IDLE;
	this->animeSwitch = false;
}

void Player::initPhysics()
{
	this->maxVelocity = 10.f;
	this->minVelocity = 1.f;
	this->acceleration = 2.f;
	this->drag = 0.93f;
	this->gravity = 2.1f;
	this->maxVelocityY = 5.f;
	this->inAir = false;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

void Player::updateMouvement()
{
	this->animeState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		this->move(-1.f, 0.f); this->animeState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->move(-1.f, 0.f); this->animeState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->move(1.f, 0.f), this->animeState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
}

void Player::updateAnimations()
{
	if (this->animeState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->clock.getElapsedTime().asSeconds() >= 0.2f || this->getAnimeSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left > 160.f) { this->currentFrame.left = 0.f; }

			this->clock.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animeState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->clock.getElapsedTime().asSeconds() >= 0.08f || this->getAnimeSwitch())
		{
			this->sprite.setScale(2.0f, 2.0f);
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left > 360.f) { this->currentFrame.left = 0.f; }

			this->clock.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animeState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->clock.getElapsedTime().asSeconds() >= 0.08f || this->getAnimeSwitch())
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left > 360) { this->currentFrame.left = 0.f; }

			this->clock.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-2.0f, 2.0f);
		this->sprite.setOrigin((this->sprite.getGlobalBounds().width / 2.f) - 13.f, 0.f);
	}
	else if (this->animeState == PLAYER_ANIMATION_STATES::FALLING)
	{
		if (this->clock.getElapsedTime().asSeconds() >= 0.08f || this->getAnimeSwitch())
		{
			this->currentFrame.top = 150.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left > 40.f) { this->currentFrame.left = 0.f; }
			this->clock.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else
	{
		this->clock.restart();
	}
}

void Player::resetAnimationTimer() { this->clock.restart(); this->animeSwitch = true; }

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocity.x) > this->maxVelocity) { this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f); }
}

void Player::updatePhysics()
{
	//Gravity
	this->velocity.y += 1.0f * this->gravity;

	if (std::abs(this->velocity.x) > this->maxVelocityY) { this->velocity.y = this->maxVelocityY * ((this->velocity.y < 0.f) ? -1.f : 1.f); }

	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
	if (std::abs(this->velocity.x) < this->minVelocity) { this->velocity.x = 0.f; }

	if (std::abs(this->velocity.y) < this->minVelocity) { this->velocity.y = 0.f; }

	this->sprite.move(this->velocity);
}

void Player::update()
{
	this->updateMouvement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target) { target.draw(this->sprite); }

void Player::resetVelocityY() { this->velocity.y = 0.f; }

const sf::FloatRect Player::getGlobalBounds() const { return this->sprite.getGlobalBounds(); }

void Player::setPosition(const float pos_x, float pos_y) { this->sprite.setPosition(pos_x, pos_y); }

const bool& Player::getAnimeSwitch()
{
	this->localAnimeSwitch = this->animeSwitch;

	if (this->animeSwitch) { this->animeSwitch = false; }

	return localAnimeSwitch;
}

const sf::Vector2f Player::getPosition() const { return this->sprite.getPosition(); }