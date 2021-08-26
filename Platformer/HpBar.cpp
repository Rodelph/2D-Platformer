#include "prcHead.h"
#include "HpBar.h"

void HpBar::initHpBarBorder()
{
	this->hpBarBorder.setFillColor(sf::Color::Transparent);
	this->hpBarBorder.setPosition(sf::Vector2f(10.f, 10.f));
	this->hpBarBorder.setOutlineColor(sf::Color::Black);
	this->hpBarBorder.setSize(sf::Vector2f(200.f, 20.f));
	this->hpBarBorder.setOutlineThickness(1.f);
}

void HpBar::initHpBarHealth()
{
	this->hpBarHealth.setFillColor(sf::Color::Red);
	this->hpBarHealth.setPosition(sf::Vector2f(10.f, 10.f));
	this->hpBarHealth.setSize(sf::Vector2f(200.f, 20.f));
}

void HpBar::initHpPoints() { this->healthBar = 200.f; }

void HpBar::renderHpBarBorder(sf::RenderTarget& target) { target.draw(this->hpBarBorder); }

void HpBar::renderHpBarHealth(sf::RenderTarget& target) { target.draw(this->hpBarHealth); }

HpBar::HpBar()
{
	initHpBarBorder();
	initHpBarHealth();
	initHpPoints();
}