#pragma once

#include "Player.h"
#include "AudioGame.h"

class Game
{
	private:
		sf::RenderWindow window;
		sf::Event ev;

		Player *player;
		AudioGame *audGame;

		void initWindow();
		void initPlayer();

	public :
		Game();
		virtual ~Game();

		void initAudio();
		void updateCollision();
		void updatePlayer();
		void update();

		void renderPlayer();
		void render();

		const sf::RenderWindow& getWindow() const;
};