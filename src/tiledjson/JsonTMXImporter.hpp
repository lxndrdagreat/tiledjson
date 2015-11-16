// JsonTMXImporter.hpp
// Panic! Medieval
//
// Dan Alexander 08/29/14
// Copyright(c) 2014
//
/* JsonTMXImporter
 *
 * This class handles importing levels from
 * TMX json files.
 */

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
