#ifndef TILELAYER_HPP
#define TILELAYER_HPP

#include <string>
#include <vector>
#include "MapLayer.hpp"

namespace te
{

class MapTileLayer : public MapLayer
{
protected:
	
	std::vector<unsigned int>	mTiles;
	
public:
	MapTileLayer();
	MapTileLayer(unsigned int width_, unsigned int height_, std::vector<unsigned int>& tiledata_);
	~MapTileLayer();
	
	void SetTileData(unsigned int width_, unsigned int height_, std::vector<unsigned int>& tiledata_);

	const std::string& GetName();
	void SetName(const std::string& name_);
	
	unsigned int GetTileAtCoordinate(unsigned int x, unsigned int y);
};

}

#endif // TILELAYER_HPP
