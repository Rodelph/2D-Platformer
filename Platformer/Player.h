#pragma once

#include "prcHead.h"

class Player
{
	private :
		void initSprite();
		void initTexture();

		sf::Sprite sprite;
		sf::Texture textureSheet;

	public : 
		Player();
		virtual ~Player();

		void update();
		void render(sf::RenderTarget &target);
};