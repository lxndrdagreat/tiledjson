#include "MapObjectGroup.hpp"

namespace TILEDJSON_NAMESPACE
{

MapObjectGroup::MapObjectGroup()
: MapLayer()
{
	mType = ObjectGroup;
}

MapObjectGroup::~MapObjectGroup()
{
	mObjectNameMap.clear();
	mObjects.clear();
}

void MapObjectGroup::addObject(MapObject &object_){
	
	mObjects.push_back(object_);
	
	if (!object_.getName().empty()){
		mObjectNameMap[object_.getName()] = mObjects.size() - 1;
	}
}

bool MapObjectGroup::hasObject(const std::string &name_){
	return mObjectNameMap.find(name_) != mObjectNameMap.end();
}

MapObject MapObjectGroup::getObjectByName(const std::string &name_){
	return mObjects[mObjectNameMap[name_]];
}

std::vector<MapObject> MapObjectGroup::getObjects(){
	return mObjects;
}

}

