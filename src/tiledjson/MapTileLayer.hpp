// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#ifndef TILELAYER_HPP
#define TILELAYER_HPP

#include <string>
#include <vector>
#include "MapLayer.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{

class MapTileLayer : public MapLayer
{
protected:
	
	std::vector<unsigned int>	mTiles;
	
public:
	MapTileLayer();
	MapTileLayer(unsigned int width_, unsigned int height_, std::vector<unsigned int>& tiledata_);
	~MapTileLayer();
	
	void 						setTileData(unsigned int width_, unsigned int height_, std::vector<unsigned int> &tiledata_);
	
	unsigned int 				getTileAtCoordinate(unsigned int x, unsigned int y);
};

}

#endif // TILELAYER_HPP
