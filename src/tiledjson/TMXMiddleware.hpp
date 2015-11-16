// TMXMiddleware.hpp
//
// Dan Alexander 01/06/2015
// Copyright(c) 2014
//
/* Utility classes for handling Tiled TMX files.
 */
 
#ifndef TMXMIDDLEWARE_HPP
#define TMXMIDDLEWARE_HPP
#include <map>
#include <vector>
#include <string>
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE {

typedef std::map<std::string, std::string> TMXProperties;
	
struct TMXTilesetDetails{
	int FirstGID;
	
	std::string ImagePath;
	
	int ImageHeight;
	int ImageWidth;
	
	int Margin = 0;
	int Spacing = 0;
	int TileHeight;
	int TileWidth;
	
	std::string Name;
	//std::map<std::string, std::map<std::string, std::string> > TileProperties;
	TilePropertyGidMap TileProperties;
};

enum TMXLayerType {
	TMXLayer_Tile,
	TMXLayer_Object,
	TMXLayer_Image,
};

enum TMXObjectKind{
	TMXObject_Rectangle,
	TMXObject_Ellipse,
	TMXObject_Polygon,
	TMXObject_Polyline,
	TMXObject_Image,
};

struct TMXPoint {
	float x;
	float y;
};

struct TMXPolyline{
	std::vector<TMXPoint> points;
};

struct TMXObject{
	std::string Name;
	std::string Type;
	
	TMXObjectKind Kind = TMXObject_Rectangle;
	
	TMXPolyline polyline;
	
	TMXProperties Properties;
	
	int X;
	int Y;
	int Width;
	int Height;	
};

struct TMXObjectGroup{
	std::string Name;
	std::vector<TMXObject> Objects;
};

struct TMXImageLayer{
	std::string Image;
	std::string Name;
	float Opacity = 1.0f;
	bool Visible;
	unsigned int Height;
	unsigned int Width;
	int X;
	int Y;
};

struct TMXLayer{
	std::string Name;
	unsigned int Height;
	unsigned int Width;
	int X = 0;
	int Y = 0;
	float Opacity = 1.0f;
	bool Visible;
	
	std::string Image;
	
	std::vector<unsigned int> Data;
	std::vector<TMXObject> Objects;
	
	TMXLayerType Type;
};

struct TMXMapDetails{
	
	int Width;
	int Height;
	int TileWidth;
	int TileHeight;
	
	TMXProperties MapProperties;
	
	std::vector<TMXTilesetDetails> Tilesets;	
	std::vector<TMXLayer> Layers;
	std::vector<TMXImageLayer> ImageLayers;
	std::vector<TMXObjectGroup> ObjectGroups;
	
	std::map<int, TMXProperties > AllTilesetProperties;
};	

} //end of te namespace


#endif