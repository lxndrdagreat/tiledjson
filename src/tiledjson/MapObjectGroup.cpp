#include "MapObjectGroup.hpp"

namespace te
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

void MapObjectGroup::AddObject(MapObject& object_){
	
	mObjects.push_back(object_);
	
	if (!object_.GetName().empty()){
		mObjectNameMap[object_.GetName()] = mObjects.size() - 1;
	}
}

bool MapObjectGroup::HasObject(const std::string& name_){
	return mObjectNameMap.find(name_) != mObjectNameMap.end();
}

MapObject MapObjectGroup::GetObjectByName(const std::string& name_){
	return mObjects[mObjectNameMap[name_]];
}

std::vector<MapObject> MapObjectGroup::GetObjects(){
	return mObjects;
}

}

