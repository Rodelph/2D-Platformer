#include "prcHead.h"
#include "TileMap.h"

TileMap::TileMap()
{
	/*
	this->gridSizeU = 50;
	this->maxSize.x = 100;
	this->maxSize.y = 100;
	this->layers = 1;

	this->tiles.resize(this->maxSize.x);

	for (size_t i = 0; i < this->maxSize.x; i++)
	{
		this->tiles.push_back(std::vector<std::vector<Tile>>());
		
		for (size_t j = 0; j < this->maxSize.y; j++)
		{
			this->tiles[i].resize(this->maxSize.y);
			this->tiles[i].push_back(std::vector<Tile>());

			for (size_t k = 0; k < this->layers; k++)
			{
				this->tiles[i][j].resize(this->layers);
				this->tiles[i][j].push_back(Tile());
			}
		}
	}
	*/
}

TileMap::~TileMap()
{

}

void TileMap::addTile(unsigned x, unsigned y)
{

}

void TileMap::removeTile()
{

}

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget& target)
{

}
