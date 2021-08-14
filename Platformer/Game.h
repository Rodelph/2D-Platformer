#pragma once

#include "prcHead.h"
#include "Player.h"

class Game
{
	private:
		sf::RenderWindow window;
		sf::Event ev;

		Player *player;

		void initWindow();
		void initPlayer();

	public :
		Game();
		virtual ~Game();

		void updatePlayer();
		void renderPlayer(sf::RenderTarget &target);
		void update();
		void render();

		const sf::RenderWindow& getWindow() const;
};