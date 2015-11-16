#ifndef MAPTILESET_HPP
#define MAPTILESET_HPP

#include <string>
#include "Property.hpp"

namespace te
{

class MapTileSet
{
private:
	unsigned int 		mFirstGID;
	unsigned int		mLastGID;
	
	std::string			mFilePath;
	
	unsigned int		mImageWidth;
	unsigned int		mImageHeight;
	
	unsigned int		mMargin;
	unsigned int		mSpacing;
	
	unsigned int		mTileHeight;
	unsigned int		mTileWidth;
	
	std::string			mName;
	
	// properties...
	TilePropertyGidMap	mTileProperties;
	
public:
	MapTileSet();
	~MapTileSet();

	unsigned int		getFirstGID();
	void				setFirstGID(unsigned int gid);
	
	unsigned int		getLastGID();
	void				setLastGID(unsigned int gid);
	
	std::string			getFilePath();
	void				setFilePath(const std::string& path);
	
	unsigned int		getImageWidth();
	void				setImageWidth(unsigned int width);
	
	unsigned int		getImageHeight();
	void				setImageHeight(unsigned int height);
	
	unsigned int		getMargin();
	void				setMargin(unsigned int margin);
	
	unsigned int		getSpacing();
	void				setSpacing(unsigned int spacing);
	
	unsigned int		getTileHeight();
	void				setTileHeight(unsigned int height);
	
	unsigned int		getTileWidth();
	void				setTileWidth(unsigned int width);
	
	std::string			getName();
	void				setName(const std::string& name);
	
	void				setPropertiesForTileGID(unsigned int gid, PropertyCollection properties);
	PropertyCollection  getPropertiesForTileGID(unsigned int gid);
	
	TilePropertyGidMap	getPropertiesForTiles();
	
	unsigned int		getTilesAcross();
	unsigned int		getTilesDown();
};

}

#endif // MAPTILESET_HPP
