#pragma once

class HpBar
{
	private :
		sf::RectangleShape hpBarBorder, hpBarHealth;
		float healthBar;

		void initHpBarBorder();
		void initHpBarHealth();
		void initHpPoints();

	public : 
		HpBar();

		void renderHpBarHealth(sf::RenderTarget &target);
		void renderHpBarBorder(sf::RenderTarget &target);
};