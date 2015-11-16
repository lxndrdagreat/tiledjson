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

namespace te
{

class TileMap
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
	TileMap();
	~TileMap();

	void 							LoadFromFile(const char* filename);
	void 							LoadFromImporter(LevelImporter* levelImporter);
	
	unsigned int 					GetWidth();
	unsigned int 					GetHeight();
	unsigned int					GetUnitWidth();
	unsigned int					GetUnitHeight();
	
	unsigned int 					TotalTileLayers();
	unsigned int 					TotalObjectLayers();
	
	std::vector<MapLayer*>			GetLayers();
	
	MapTileLayer*		 			GetTileLayerByName(const std::string& name_);
	
	std::vector<unsigned int> 		GetTilesAtCoordinate(unsigned int x, unsigned int y);
	
	PropertyCollection 				GetAllPropertiesForCoordinate(unsigned int x, unsigned int y);
	
	MapObjectGroup*					GetObjectGroupAtIndex(unsigned int index);
	MapObjectGroup*					GetObjectGroupByName(const std::string& name);
	
	std::vector<MapObject>			GetObjectsByName(const std::string& name);
	
	MapTileSet&						GetTileSetByName(const std::string& name);
	MapTileSet&						GetTileSetByFirstGID(unsigned int gid);
	
	std::map<unsigned int, std::string>	GetTilesetImagePathsWithGIDs();
	std::vector<std::string>			GetTilesetImagePaths();
	
	std::vector<MapImageLayer*>			GetImageLayers();
	MapImageLayer*						GetImageLayerByName(const std::string& name);
};

}

#endif // TILEMAP_HPP
