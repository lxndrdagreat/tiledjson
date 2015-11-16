// LevelImporter.hpp
// Panic! Medieval
//
// Dan Alexander 08/31/14
// Copyright(c) 2014
//
/* LevelImporter
 *
 * Parent class for all Level Importers.
 */
#ifndef LEVELIMPORTER_HPP
#define LEVELIMPORTER_HPP

#include <vector>
#include <map>
#include "MapTileLayer.hpp"
#include "Property.hpp"
#include "MapLayer.hpp"
#include "MapObjectGroup.hpp"
#include "MapTileSet.hpp"
#include "MapImageLayer.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE {

class LevelImporter
{
public:
	LevelImporter();
	virtual ~LevelImporter();

	virtual int getMapWidth() { return 0; }
	virtual int getMapHeight() { return 0; }
	virtual int getMapUnitWidth() { return 0; }
	virtual int getMapUnitHeight() { return 0; }

	virtual bool load() { return false; };
	virtual std::map<std::string, std::string> getMapProperties() { return std::map<std::string, std::string>(); };
	
	virtual std::vector<MapLayer*> getLayers() { return std::vector<MapLayer*>(); };
	
	virtual std::vector<MapTileLayer*> getMapTileLayers() { return std::vector<MapTileLayer*>(); };
	
	virtual TilePropertyGidMap getTileProperties() { return TilePropertyGidMap(); };
	
	virtual std::vector<MapObjectGroup*> getObjectGroups() { return std::vector<MapObjectGroup*>(); };
	
	virtual std::vector<MapTileSet> getTileSets() { return std::vector<MapTileSet>(); }
	
	virtual std::vector<MapImageLayer*> getImageLayers() { return std::vector<MapImageLayer*>(); };
};

}

#endif // LEVELIMPORTER_HPP
