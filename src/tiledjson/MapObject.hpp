#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP

#include <string>
#include "Property.hpp"
#include <vector>
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{
	
enum MapObjectKind {
	MapObject_Rectangle,
	MapObject_Ellipse,
	MapObject_Polygon,
	MapObject_Polyline,
	MapObject_Image,
};

struct PolylinePoint {
	float x;
	float y;
};

struct Polyline {
	std::vector<PolylinePoint> points;
};

class MapObject
{
private:

	MapObjectKind				mKind;
	std::string 				mName;
	std::string					mType;
	bool						mIsEllipse;
	
	PropertyCollection			mProperties;
	
	Polyline					mPolyline;
	
	float						mX;
	float						mY;
	float						mWidth;
	float						mHeight;	

public:
	MapObject();
	~MapObject();
	
	void						setProperty(const std::string &key_, const std::string &value_);
	PropertyCollection			getProperties();
	bool						hasProperty(const std::string &key_);
	std::string					getProperty(const std::string &key_);
	
	float						getWidth();
	float						getHeight();
	void						setWidth(float width_);
	void						setHeight(float height_);
	
	float						getX();
	void						setX(float x_);
	float						getY();
	void						setY(float y_);
	
	std::string					getName();
	void						setName(const std::string &name_);
	
	MapObjectKind				getKind();
	void						setKind(MapObjectKind kind_);
	
	Polyline					getPolyline();
	void						setPolyLine(const Polyline &polyline);
};

}

#endif // MAPOBJECT_HPP
