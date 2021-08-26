#pragma once

#include "Tile.h"

class TileMap
{
	private:
		unsigned gridSizeU, layers;
		sf::Vector2u maxSize;
		std::vector<std::vector<std::vector<Tile>>> tiles;

	public :
		TileMap();
		virtual ~TileMap();

		void addTile(unsigned x, unsigned y);
		void removeTile();

		void update();
		void render(sf::RenderTarget &target);
};