#pragma once

class Tile
{	
	private:
		sf::Sprite sprite;
		const bool damaging;

	public:
		Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);
		virtual ~Tile();

		const sf::FloatRect getGlobalBounds() const;

		void update();
		void render(sf::RenderTarget &target);
};