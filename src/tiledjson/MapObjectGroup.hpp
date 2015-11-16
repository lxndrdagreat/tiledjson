// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

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
