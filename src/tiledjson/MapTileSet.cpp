#include "MapTileSet.hpp"
#include <cmath>

namespace te
{

MapTileSet::MapTileSet()
{
}

MapTileSet::~MapTileSet()
{
}

std::string te::MapTileSet::getFilePath()
{
	return mFilePath;
}

unsigned int te::MapTileSet::getFirstGID()
{
	return mFirstGID;
}

unsigned int te::MapTileSet::getImageHeight()
{
	return mImageHeight;
}

unsigned int te::MapTileSet::getImageWidth()
{
	return mImageWidth;
}

unsigned int te::MapTileSet::getLastGID()
{
	return mLastGID;
}

unsigned int te::MapTileSet::getMargin()
{
	return mMargin;
}

std::string te::MapTileSet::getName()
{
	return mName;
}

unsigned int te::MapTileSet::getSpacing()
{
	return mSpacing;
}

unsigned int te::MapTileSet::getTileHeight()
{
	return mTileHeight;
}

unsigned int te::MapTileSet::getTileWidth()
{
	return mTileWidth;
}

void te::MapTileSet::setFilePath(const std::string& path)
{
	mFilePath = path;
}

void te::MapTileSet::setFirstGID(unsigned int gid)
{
	mFirstGID = gid;
}

void te::MapTileSet::setImageHeight(unsigned int height)
{
	mImageHeight = height;
}

void te::MapTileSet::setImageWidth(unsigned int width)
{
	mImageWidth = width;
}

void te::MapTileSet::setLastGID(unsigned int gid)
{
	mLastGID = gid;
}

void te::MapTileSet::setMargin(unsigned int margin)
{
	mMargin = margin;
}

void te::MapTileSet::setName(const std::string& name)
{
	mName = name;
}

void te::MapTileSet::setSpacing(unsigned int spacing)
{
	mSpacing = spacing;
}

void te::MapTileSet::setTileHeight(unsigned int height)
{
	mTileHeight = height;
}

void te::MapTileSet::setTileWidth(unsigned int width)
{
	mTileWidth = width;
}

void te::MapTileSet::setPropertiesForTileGID(unsigned int gid, PropertyCollection properties){
	mTileProperties[gid] = properties;
}

PropertyCollection te::MapTileSet::getPropertiesForTileGID(unsigned int gid){
	return mTileProperties[gid];
}

TilePropertyGidMap te::MapTileSet::getPropertiesForTiles(){
	return mTileProperties;
}

unsigned int te::MapTileSet::getTilesAcross(){
	return (int)ceilf((float)mImageWidth / (float)(mTileWidth + mSpacing));
}

unsigned int te::MapTileSet::getTilesDown(){
	return mImageHeight / (mTileHeight + mSpacing);
}

} // end of namespace