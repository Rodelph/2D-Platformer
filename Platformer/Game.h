#pragma once

#include "Player.h"
#include "AudioGame.h"
#include "HpBar.h"
#include "EnergyBar.h"

class Game
{
	private:
		sf::RenderWindow window;
		sf::Event ev;

		Player *player;
		HpBar* hpBar;
		AudioGame *audGame;
		EnergyBar* enerBar;

		void initWindow();
		void initPlayer();
		void initAudio();
		void initHpBar();
		void initEnerBar();

	public :
		Game();
		virtual ~Game();

		void updateCollision();
		void updatePlayer();
		//void updateHpBar();
		//void updateEnerBar();
		void update();

		void renderHpBar();
		void renderEnerBar();
		void renderPlayer();
		void Render();

		const sf::RenderWindow& getWindow() const;
};