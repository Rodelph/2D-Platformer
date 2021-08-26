#include "prcHead.h"
#include "EnergyBar.h"

void EnergyBar::initEnergyPoints() { this->energyPoints = 100.f; }

void EnergyBar::initEnergyBorder() 
{
	this->energyBarBorder.setFillColor(sf::Color::Transparent);
	this->energyBarBorder.setOutlineColor(sf::Color::Black);
	this->energyBarBorder.setOutlineThickness(1.f);
	this->energyBarBorder.setPosition(10.f, 40.f);
	this->energyBarBorder.setSize(sf::Vector2f(200.f, 20.f));
}

void EnergyBar::initEnergyBarLevel()
{
	this->energyBarLevel.setFillColor(sf::Color::Blue);
	this->energyBarLevel.setPosition(10.f, 40.f);
	this->energyBarLevel.setSize(sf::Vector2f(200.f, 20.f));
}

void EnergyBar::renderEnergyBarBorder(sf::RenderTarget& target) { target.draw(this->energyBarBorder); }

void EnergyBar::renderEnergyBarLevel(sf::RenderTarget& target) { target.draw(this->energyBarLevel); }

EnergyBar::EnergyBar()
{
	this->initEnergyPoints();
	this->initEnergyBorder();
	this->initEnergyBarLevel();
}