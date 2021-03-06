// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#ifndef MAPIMAGELAYER_HPP
#define MAPIMAGELAYER_HPP

#include <string>
#include "MapLayer.hpp"
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE
{

class MapImageLayer : public MapLayer
{
protected:

	std::string				mFilePath;
	
public:
	MapImageLayer();
	MapImageLayer(const std::string& name, const std::string& path, int x, int y, unsigned int width, unsigned int height);
	~MapImageLayer();
	
	void						setPosition(int x, int y);
	
	std::string					getFilePath();
	void						setFilePath(const std::string& path);
};

}

#endif // MAPIMAGELAYER_HPP
