// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#ifndef JSONTMXIMPORTER_HPP
#define JSONTMXIMPORTER_HPP

#include "LevelImporter.hpp" // parent class
#include <string>
#include <map>
#include <vector>
#include "TMXMiddleware.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{

class JsonTMXImporter : public LevelImporter
{
private:
	
	TMXMapDetails		mMapDetails;
	
	bool				mMapDetailsLoaded;
	
public:
	JsonTMXImporter();
	~JsonTMXImporter();

	bool load(const char *filename);
	
	bool loadTMXJson(const char *filename);

	int getMapWidth();
	int getMapHeight();
	int getMapUnitWidth() { return mMapDetails.TileWidth; }
	int getMapUnitHeight() { return mMapDetails.TileHeight; }
	
	std::map<std::string, std::string> getMapProperties();

	std::vector<MapLayer*> getLayers();
	
	TilePropertyGidMap getTileProperties();
	
	std::vector<MapTileSet> getTileSets();
	
};

}

#endif // JSONTMXIMPORTER_HPP
