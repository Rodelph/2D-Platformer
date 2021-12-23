#pragma once

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Player
{
	private:
		void initSprite();
		void initTexture();
		void initAnimations();
		void initVariables();
		void initPhysics();

		sf::Sprite sprite;
		sf::Texture textureSheet;
		sf::IntRect currentFrame;
		sf::Clock clock;
		sf::Vector2f velocity;

		float gravity, acceleration, drag, maxVelocity, minVelocity, maxVelocityY;
		short animeState;
		bool animeSwitch, inAir, localAnimeSwitch;

	public:
		Player();

		void resetAnimationTimer();
		void move(const float dir_x, const float dir_y);
		void jump(const float bounce);

		void setPosition(const float pos_x, float pos_y);
		const sf::Vector2f getPosition() const;
		void resetVelocityY();
		const bool& getAnimeSwitch();
		const sf::FloatRect getGlobalBounds() const;

		void updatePhysics();
		void updateMouvement();
		void updateAnimations();

		void update();
		void render(sf::RenderTarget& target);
};