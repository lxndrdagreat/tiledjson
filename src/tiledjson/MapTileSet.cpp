#include "MapTileSet.hpp"
#include <cmath>

namespace TILEDJSON_NAMESPACE
{

MapTileSet::MapTileSet()
{
}

MapTileSet::~MapTileSet()
{
}

std::string MapTileSet::getFilePath()
{
	return mFilePath;
}

unsigned int MapTileSet::getFirstGID()
{
	return mFirstGID;
}

unsigned int MapTileSet::getImageHeight()
{
	return mImageHeight;
}

unsigned int MapTileSet::getImageWidth()
{
	return mImageWidth;
}

unsigned int MapTileSet::getLastGID()
{
	return mLastGID;
}

unsigned int MapTileSet::getMargin()
{
	return mMargin;
}

std::string MapTileSet::getName()
{
	return mName;
}

unsigned int MapTileSet::getSpacing()
{
	return mSpacing;
}

unsigned int MapTileSet::getTileHeight()
{
	return mTileHeight;
}

unsigned int MapTileSet::getTileWidth()
{
	return mTileWidth;
}

void MapTileSet::setFilePath(const std::string& path)
{
	mFilePath = path;
}

void MapTileSet::setFirstGID(unsigned int gid)
{
	mFirstGID = gid;
}

void MapTileSet::setImageHeight(unsigned int height)
{
	mImageHeight = height;
}

void MapTileSet::setImageWidth(unsigned int width)
{
	mImageWidth = width;
}

void MapTileSet::setLastGID(unsigned int gid)
{
	mLastGID = gid;
}

void MapTileSet::setMargin(unsigned int margin)
{
	mMargin = margin;
}

void MapTileSet::setName(const std::string& name)
{
	mName = name;
}

void MapTileSet::setSpacing(unsigned int spacing)
{
	mSpacing = spacing;
}

void MapTileSet::setTileHeight(unsigned int height)
{
	mTileHeight = height;
}

void MapTileSet::setTileWidth(unsigned int width)
{
	mTileWidth = width;
}

void MapTileSet::setPropertiesForTileGID(unsigned int gid, PropertyCollection properties){
	mTileProperties[gid] = properties;
}

PropertyCollection MapTileSet::getPropertiesForTileGID(unsigned int gid){
	return mTileProperties[gid];
}

TilePropertyGidMap MapTileSet::getPropertiesForTiles(){
	return mTileProperties;
}

unsigned int MapTileSet::getTilesAcross(){
	return (int)ceilf((float)mImageWidth / (float)(mTileWidth + mSpacing));
}

unsigned int MapTileSet::getTilesDown(){
	return mImageHeight / (mTileHeight + mSpacing);
}

} // end of namespace