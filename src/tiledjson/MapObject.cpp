#include "MapObject.hpp"

namespace TILEDJSON_NAMESPACE
{

MapObject::MapObject()
:mKind(MapObject_Rectangle)
{
}

MapObject::~MapObject()
{
}

void MapObject::SetProperty(const std::string& key_, const std::string& value_){
	mProperties.set(key_, value_);
}

bool MapObject::HasProperty(const std::string& key_){
	return mProperties.hasKey(key_);
}

std::string MapObject::GetProperty(const std::string& key_){
	return mProperties[key_].value;
}

PropertyCollection MapObject::GetProperties(){
	return mProperties;
}

float MapObject::GetHeight()
{
	return mHeight;
}

std::string MapObject::GetName()
{
	return mName;
}

float MapObject::GetWidth()
{
	return mWidth;
}

float MapObject::GetX()
{
	return mX;
}

float MapObject::GetY()
{
	return mY;
}

void MapObject::SetHeight(float height_)
{
	mHeight = height_;
}

void MapObject::SetName(const std::string& name_)
{
	mName = name_;
}

void MapObject::SetWidth(float width_)
{
	mWidth = width_;
}

void MapObject::SetX(float x_)
{
	mX = x_;
}

void MapObject::SetY(float y_)
{
	mY = y_;
}

MapObjectKind MapObject::GetKind(){
	return mKind;
}

void MapObject::SetKind(MapObjectKind kind_){
	mKind = kind_;
}

Polyline MapObject::GetPolyline(){
	return mPolyline;
}

void MapObject::SetPolyLine(const Polyline& polyline){
	mPolyline = polyline;
}

}