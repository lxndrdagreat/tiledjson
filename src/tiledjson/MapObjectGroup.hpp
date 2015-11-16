#ifndef MAPOBJECTGROUP_HPP
#define MAPOBJECTGROUP_HPP

#include <string>
#include <map>
#include <vector>
#include "MapObject.hpp"
#include "MapLayer.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{

class MapObjectGroup : public MapLayer
{
protected:

	std::vector<MapObject>					mObjects;
	std::map<std::string, unsigned int>		mObjectNameMap;

public:
	MapObjectGroup();
	~MapObjectGroup();

	void					addObject(MapObject &object_);
	bool					hasObject(const std::string &name_);
	MapObject				getObjectByName(const std::string &name_);
	
	std::vector<MapObject>	getObjects();
};

}

#endif // MAPOBJECTGROUP_HPP
