#ifndef MAPOBJECTGROUP_HPP
#define MAPOBJECTGROUP_HPP

#include <string>
#include <map>
#include <vector>
#include "MapObject.hpp"
#include "MapLayer.hpp"

namespace te
{

class MapObjectGroup : public MapLayer
{
protected:

	std::vector<MapObject>					mObjects;
	std::map<std::string, unsigned int>		mObjectNameMap;

public:
	MapObjectGroup();
	~MapObjectGroup();

	void					AddObject(MapObject& object_);
	bool					HasObject(const std::string& name_);
	MapObject				GetObjectByName(const std::string& name_);
	
	std::vector<MapObject>	GetObjects();
};

}

#endif // MAPOBJECTGROUP_HPP
