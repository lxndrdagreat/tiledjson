// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

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

void MapObject::setProperty(const std::string &key_, const std::string &value_){
	mProperties.set(key_, value_);
}

bool MapObject::hasProperty(const std::string &key_){
	return mProperties.hasKey(key_);
}

std::string MapObject::getProperty(const std::string &key_){
	return mProperties[key_].value;
}

PropertyCollection MapObject::getProperties(){
	return mProperties;
}

float MapObject::getHeight()
{
	return mHeight;
}

std::string MapObject::getName()
{
	return mName;
}

float MapObject::getWidth()
{
	return mWidth;
}

float MapObject::getX()
{
	return mX;
}

float MapObject::getY()
{
	return mY;
}

void MapObject::setHeight(float height_)
{
	mHeight = height_;
}

void MapObject::setName(const std::string &name_)
{
	mName = name_;
}

void MapObject::setWidth(float width_)
{
	mWidth = width_;
}

void MapObject::setX(float x_)
{
	mX = x_;
}

void MapObject::setY(float y_)
{
	mY = y_;
}

MapObjectKind MapObject::getKind(){
	return mKind;
}

void MapObject::setKind(MapObjectKind kind_){
	mKind = kind_;
}

Polyline MapObject::getPolyline(){
	return mPolyline;
}

void MapObject::setPolyLine(const Polyline &polyline){
	mPolyline = polyline;
}

}