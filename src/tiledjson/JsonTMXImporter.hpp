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
	std::string GetFileContents(const char* filename);
	
	TMXMapDetails		mMapDetails;
	
	bool				mMapDetailsLoaded;
	
public:
	JsonTMXImporter();
	~JsonTMXImporter();

	bool Load(const char* filename);
	
	bool LoadTMXJson(const char* filename);

	int GetMapWidth();
	int GetMapHeight();
	int GetMapUnitWidth() { return mMapDetails.TileWidth; }
	int GetMapUnitHeight() { return mMapDetails.TileHeight; }
	
	std::map<std::string, std::string> GetMapProperties();

	std::vector<MapLayer*> GetLayers();
	
	TilePropertyGidMap GetTileProperties();
	
	std::vector<MapTileSet> GetTileSets();
	
};

}

#endif // JSONTMXIMPORTER_HPP
