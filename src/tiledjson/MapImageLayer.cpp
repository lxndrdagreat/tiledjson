#include "MapImageLayer.hpp"

namespace te
{

MapImageLayer::MapImageLayer()
: MapLayer()
{
}

MapImageLayer::MapImageLayer(const std::string& name, const std::string& path, int x, int y, unsigned int width, unsigned int height)
:MapLayer()
{
	mType = ImageLayer;
	mName = name;
	mFilePath = path;
	mX = x;
	mY = y;
	mWidth = width;
	mHeight = height;
}

MapImageLayer::~MapImageLayer()
{
}

void MapImageLayer::setPosition(int x, int y){
	mX = x;
	mY = y;
}

std::string MapImageLayer::getFilePath(){
	return mFilePath;
}

void MapImageLayer::setFilePath(const std::string& path){
	mFilePath = path;
}

}

