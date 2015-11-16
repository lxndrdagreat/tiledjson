// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <map>
#include <vector>
#include <string>
#include "LevelImporter.hpp"
#include "MapLayer.hpp"
#include "MapTileLayer.hpp"
#include "Property.hpp"
#include "MapObjectGroup.hpp"
#include "MapObject.hpp"
#include "MapTileSet.hpp"
#include "MapImageLayer.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{

class TiledMap
{
private:

	// All Layers are stored in one vector, based on their order in the map data.
	// This will help us handle drawing in order.
	std::vector<MapLayer*>						mLayers;
	

	// Using map instead of vector, because not all tiles will have properties.
	TilePropertyGidMap 							mTileProperties;

	// All tile layers
	// Each value is an index for mLayers;
	//std::vector<MapTileLayer>					mTileLayers;
	std::vector<unsigned int>					mTileLayers;
	
	// Maps names of tile layers to their index in the vector.
	std::map<std::string, unsigned int>			mTileLayerNameMap;
	
	// Tilesets
	std::vector<MapTileSet>						mTilesets;
	std::map<unsigned int, unsigned int>		mTilesetsFirstGIDMap;
	std::map<std::string, unsigned int>			mTilesetsNameMap;
	
	// Map object layers
	//std::vector<MapObjectGroup>				mObjectGroups;
	std::vector<unsigned int>					mObjectGroups;
	std::map<std::string, unsigned int>			mObjectGroupNameMap;
	
	// Map Image Layers
	//std::vector<MapImageLayer>					mImageLayers;
	std::vector<unsigned int>					mImageLayers;
	std::map<std::string, unsigned int>			mImageLayersNameMap;
	
	// Map details
	unsigned int								mWidth;
	unsigned int								mHeight;
	unsigned int								mUnitWidth;
	unsigned int 								mUnitHeight;
	
public:
	TiledMap();
	~TiledMap();

	void 							loadFromFile(const char *filename);
	void 							loadFromImporter(LevelImporter *levelImporter);
	
	unsigned int 					getWidth();
	unsigned int 					getHeight();
	unsigned int					getUnitWidth();
	unsigned int					getUnitHeight();
	
	unsigned int 					totalTileLayers();
	unsigned int 					totalObjectLayers();
	
	std::vector<MapLayer*>			getLayers();
	
	MapTileLayer*					getTileLayerByName(const std::string &name_);
	
	std::vector<unsigned int> 		getTilesAtCoordinate(unsigned int x, unsigned int y);
	
	PropertyCollection 				getAllPropertiesForCoordinate(unsigned int x, unsigned int y);
	
	MapObjectGroup*					getObjectGroupAtIndex(unsigned int index);
	MapObjectGroup*					getObjectGroupByName(const std::string &name);
	
	std::vector<MapObject>			getObjectsByName(const std::string &name);
	
	MapTileSet&						getTileSetByName(const std::string &name);
	MapTileSet&						getTileSetByFirstGID(unsigned int gid);
	
	std::map<unsigned int, std::string>	getTilesetImagePathsWithGIDs();
	std::vector<std::string>			getTilesetImagePaths();
	
	std::vector<MapImageLayer*>			getImageLayers();
	MapImageLayer*						getImageLayerByName(const std::string &name);
};

}

#endif // TILEMAP_HPP
