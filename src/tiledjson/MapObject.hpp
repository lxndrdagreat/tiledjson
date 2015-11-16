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
	
	void						SetProperty(const std::string& key_, const std::string& value_);
	PropertyCollection			GetProperties();
	bool						HasProperty(const std::string& key_);
	std::string					GetProperty(const std::string& key_);
	
	float						GetWidth();
	float						GetHeight();
	void						SetWidth(float width_);
	void						SetHeight(float height_);
	
	float						GetX();
	void						SetX(float x_);
	float						GetY();
	void						SetY(float y_);
	
	std::string					GetName();
	void						SetName(const std::string& name_);
	
	MapObjectKind				GetKind();
	void						SetKind(MapObjectKind kind_);
	
	Polyline					GetPolyline();
	void						SetPolyLine(const Polyline& polyline);
};

}

#endif // MAPOBJECT_HPP
