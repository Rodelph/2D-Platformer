#pragma once

class EnergyBar
{
	private:
		sf::RectangleShape energyBarBorder, energyBarLevel;
		float energyPoints;

		void initEnergyBorder();
		void initEnergyBarLevel();
		void initEnergyPoints();

	public:
		EnergyBar();

		void renderEnergyBarBorder(sf::RenderTarget& target);
		void renderEnergyBarLevel(sf::RenderTarget& target);
};