// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#ifndef TILEPROPERTY_H
#define TILEPROPERTY_H

#include <string>
#include <map>
#include <vector>
#include "tiledjsonconsts.hpp"

namespace TILEDJSON_NAMESPACE{

	//typedef std::map<std::string, std::string> TilePropertyMap;	
	//typedef std::map<std::string, std::string> PropertyCollection;

	struct Property {
		std::string key;
		std::string value;
		
		int asInt(){
			return atoi(value.c_str());
		}
		
		std::string asString(){
			return value;
		}
		
		const char*asCString(){
			return value.c_str();
		}
	};
	
	class PropertyCollection {
		private:
			std::vector<Property>					mProperties;
			std::map<std::string, unsigned int>		mPropertiesNameMap;
			
		public:
			PropertyCollection();
			~PropertyCollection();
			
			bool									hasKey(const std::string& key);
			
			void									set(const std::string& key, const std::string& value);
			Property								get(const std::string& key);
			
			void									add(Property property);
			
			std::string								getValue(const std::string& key);
			int										getValueAsInt(const std::string& key);
			
			// subscript operator overloading
			Property&								operator[] (const std::string& key);
			
			std::vector<std::string>				keys();
	};
	
	typedef std::map<unsigned int, PropertyCollection> TilePropertyGidMap;
}
#endif