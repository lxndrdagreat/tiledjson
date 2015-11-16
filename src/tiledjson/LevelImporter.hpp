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

namespace te
{

class LevelImporter
{
public:
	LevelImporter();
	virtual ~LevelImporter();

	virtual int GetMapWidth() { return 0; }
	virtual int GetMapHeight() { return 0; }
	virtual int GetMapUnitWidth() { return 0; }
	virtual int GetMapUnitHeight() { return 0; }

	virtual bool Load() { return false; };
	virtual std::map<std::string, std::string> GetMapProperties() { return std::map<std::string, std::string>(); };
	
	virtual std::vector<MapLayer*> GetLayers() { return std::vector<MapLayer*>(); };
	
	virtual std::vector<MapTileLayer*> GetMapTileLayers() { return std::vector<MapTileLayer*>(); };
	
	virtual TilePropertyGidMap GetTileProperties() { return TilePropertyGidMap(); };
	
	virtual std::vector<MapObjectGroup*> GetObjectGroups() { return std::vector<MapObjectGroup*>(); };
	
	virtual std::vector<MapTileSet> GetTileSets() { return std::vector<MapTileSet>(); }
	
	virtual std::vector<MapImageLayer*> GetImageLayers() { return std::vector<MapImageLayer*>(); };
};

}

#endif // LEVELIMPORTER_HPP
