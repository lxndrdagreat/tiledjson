// Copyright 2015 Dan Alexander
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at https://github.com/lxndrdagreat/tiledjson/blob/master/LICENSE

#include "Property.hpp"

namespace TILEDJSON_NAMESPACE{
	
	PropertyCollection::PropertyCollection(){
	
	}
	
	PropertyCollection::~PropertyCollection(){
		
	}
	
	bool PropertyCollection::hasKey(const std::string& key){
		return mPropertiesNameMap.find(key) != mPropertiesNameMap.end();
	}
	
	void PropertyCollection::set(const std::string& key, const std::string& value){
		Property tp;
		tp.key = key;
		tp.value = value;
		
		mProperties.push_back(tp);
		mPropertiesNameMap[tp.key] = mProperties.size() - 1;
	}
	
	Property PropertyCollection::get(const std::string& key){
		return mProperties[mPropertiesNameMap[key]];
	}
	
	std::string PropertyCollection::getValue(const std::string& key){
		return mProperties[mPropertiesNameMap[key]].value;
	}
	
	int PropertyCollection::getValueAsInt(const std::string& key){
		return mProperties[mPropertiesNameMap[key]].asInt();
	}
	
	void PropertyCollection::add(Property property){
		mProperties.push_back(property);
		mPropertiesNameMap[property.key] = mProperties.size() - 1;
	}
	
	Property& PropertyCollection::operator [](const std::string& key){
		return mProperties[mPropertiesNameMap[key]];
	}
	
	std::vector<std::string> PropertyCollection::keys(){
		std::vector<std::string> keys;
		
		for (Property& prop : mProperties){
			keys.push_back(prop.key);
		}
		
		return keys;
	}
}