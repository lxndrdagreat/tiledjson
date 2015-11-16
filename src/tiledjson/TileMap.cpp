#include "TileMap.hpp"
#include "JsonTMXImporter.hpp"
#include <iostream>

namespace TILEDJSON_NAMESPACE
{

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
	mTileLayerNameMap.clear();
	mTileLayers.clear();
	mTileProperties.clear();
	mImageLayersNameMap.clear();
	mImageLayers.clear();
	mTilesets.clear();
	mTilesetsFirstGIDMap.clear();
	mTilesetsNameMap.clear();
	
	for (unsigned int i = 0; i < mLayers.size(); ++i){
		if (mLayers[i] != nullptr){
			delete mLayers[i];
			mLayers[i] = nullptr;
		}
	}
	
	mLayers.clear();
}

void TileMap::loadFromFile(const char *filename){
	// by default, we use the json importer
	JsonTMXImporter* jsonImporter = new JsonTMXImporter();
	jsonImporter->Load(filename);
	this->loadFromImporter(jsonImporter);
	delete jsonImporter;
}

void TileMap::loadFromImporter(LevelImporter *levelImporter){
	
	// Get Map Data
	
	mWidth = levelImporter->GetMapWidth();
	mHeight = levelImporter->GetMapHeight();
	mUnitHeight = levelImporter->GetMapUnitHeight();
	mUnitWidth = levelImporter->GetMapUnitWidth();
	
	// Get Tile Sets
	mTilesets = levelImporter->GetTileSets();
	
	for (unsigned int i = 0; i < mTilesets.size(); ++i){
		mTilesetsFirstGIDMap[mTilesets[i].getFirstGID()] = i;
		mTilesetsNameMap[mTilesets[i].getName()] = i;
		
//		for (auto& kv : mTilesets[i].getPropertiesForTiles()){
//			mTileProperties[kv.first + mTilesets[i].getFirstGID()] = kv.second;
//		}
		
		//std::cout << mTilesets[i].getImageWidth() << "," << mTilesets[i].getTileWidth() << std::endl;
	}
	
	// Get tile properties
	mTileProperties = levelImporter->GetTileProperties();
	

	
	// Get all layers
	mLayers = levelImporter->GetLayers();
	for (unsigned int i = 0; i < mLayers.size(); ++i){
		MapLayer* layer = mLayers[i];
		if (layer->getType() == TileLayer){
			mTileLayers.push_back(i);
			mTileLayerNameMap[layer->getName()] = i;
		}
		else if (layer->getType() == ObjectGroup){
			mObjectGroups.push_back(i);
			mObjectGroupNameMap[layer->getName()] = i;
		}
		else if (layer->getType() == ImageLayer){
			mImageLayers.push_back(i);
			mImageLayersNameMap[layer->getName()] = i;
		}
	}

	mUnitWidth = levelImporter->GetMapUnitWidth();
	mUnitHeight = levelImporter->GetMapUnitHeight();
}

unsigned int TileMap::totalTileLayers(){
	return mTileLayers.size();
}

unsigned int TileMap::totalObjectLayers(){
	return mObjectGroups.size();
}

std::vector<MapLayer*> TileMap::getLayers(){
	return mLayers;
}

MapTileLayer* TileMap::getTileLayerByName(const std::string &name_){
	return (MapTileLayer*)mLayers[mTileLayerNameMap[name_]];
}

unsigned int TileMap::getWidth(){
	return mWidth;
}

unsigned int TileMap::getHeight(){
	return mHeight;
}

unsigned int TileMap::getUnitWidth(){
	return mUnitWidth;
}

unsigned int TileMap::getUnitHeight(){
	return mUnitHeight;
}

std::vector<unsigned int> TileMap::getTilesAtCoordinate(unsigned int x, unsigned int y){
	std::vector<unsigned int> return_tiles;
	
	for (unsigned int i = 0; i < mTileLayers.size(); ++i){
		return_tiles.push_back(((MapTileLayer*)mLayers[mTileLayers[i]])->GetTileAtCoordinate(x, y));
	}
	
	return return_tiles;
}

PropertyCollection TileMap::getAllPropertiesForCoordinate(unsigned int x, unsigned int y){
	PropertyCollection all_properties;
	
	std::vector<unsigned int> tiles = getTilesAtCoordinate(x, y);
	
	// loop through the tiles and get all properties
	for (unsigned int i = 0; i < tiles.size(); ++i){
		if (tiles[i] == 0){
			continue;
		}
		if (mTileProperties.find(tiles[i]) == mTileProperties.end()){
			continue;
		}
		
//		for (auto& kv : mTileProperties[tiles[i]]) {
//			 The current issue with this is that it does not handle duplicates or conflicting properties.
//			all_properties[kv.first] = kv.second;
//		}
		for (auto& key : mTileProperties[tiles[i]].keys()){
			all_properties.set(key, mTileProperties[tiles[i]][key].value);
		}
	}
	
	return all_properties;
}

MapObjectGroup* TileMap::getObjectGroupByName(const std::string &name){
	return (MapObjectGroup*)mLayers[mObjectGroupNameMap[name]];
}

std::vector<MapObject> TileMap::getObjectsByName(const std::string &name){
	std::vector<MapObject> objects;
	
	for (unsigned int i = 0; i < mObjectGroups.size(); ++i){
		if (((MapObjectGroup*)mLayers[mObjectGroups[i]])->HasObject(name)){
			objects.push_back(((MapObjectGroup*)mLayers[mObjectGroups[i]])->GetObjectByName(name));
		}
	}
	
	return objects;
}

MapTileSet& TileMap::getTileSetByName(const std::string &name){
	return mTilesets[mTilesetsNameMap[name]];
}

MapTileSet& TileMap::getTileSetByFirstGID(unsigned int gid){
	return mTilesets[mTilesetsFirstGIDMap[gid]];
}

std::map<unsigned int, std::string> TileMap::getTilesetImagePathsWithGIDs(){
	std::map<unsigned int, std::string> paths;
	
	for (auto& tileset : mTilesets){
		paths[tileset.getFirstGID()] = tileset.getFilePath();
	}
	
	return paths;
}

std::vector<std::string> TileMap::getTilesetImagePaths(){
	std::vector<std::string> paths;
	
	for (auto& tileset : mTilesets){
		paths.push_back(tileset.getFilePath());
	}
	
	return paths;
}

std::vector<MapImageLayer*> TileMap::getImageLayers(){
	std::vector<MapImageLayer*> layers;
	
	for (unsigned int i = 0; i < mImageLayers.size(); ++i){
		layers.push_back((MapImageLayer*)mLayers[mImageLayers[i]]);
	}
	
	return layers;
}

MapImageLayer* TileMap::getImageLayerByName(const std::string &name){
	return (MapImageLayer*)mLayers[mImageLayersNameMap[name]];
}

}

