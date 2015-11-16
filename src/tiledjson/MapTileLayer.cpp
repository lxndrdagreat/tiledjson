#include "MapTileLayer.hpp"
#include <iostream>

namespace te
{
	
MapTileLayer::MapTileLayer()
{
	mX = 0;
	mY = 0;
	mType = TileLayer;
}

MapTileLayer::MapTileLayer(unsigned int width_, unsigned int height_, std::vector<unsigned int>& tiledata_)
{
	mX = 0;
	mY = 0;
	SetTileData(width_, height_, tiledata_);
	mType = TileLayer;
}

MapTileLayer::~MapTileLayer()
{
	mTiles.clear();
}


void MapTileLayer::SetTileData(unsigned int width_, unsigned int height_, std::vector<unsigned int>& tiledata_){
	
	mTiles.clear();
	
	mWidth = width_;
	mHeight = height_;
	
	for (unsigned int i = 0; i < tiledata_.size(); ++i){
		mTiles.push_back(tiledata_[i]);
	}
	
}

unsigned int MapTileLayer::GetTileAtCoordinate(unsigned int x, unsigned int y){
	if (x < mX || y < mY || x >= mX + mWidth || y >= mY + mHeight){
		// coordindate is outside the bounds of this layer.
		return 0;
	}

	x = x - mX;
	y = y - mY;
	
	unsigned int index = y * mWidth + x;
	
	return mTiles[index];
}

}

