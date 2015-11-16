#ifndef TILEPROPERTY_H
#define TILEPROPERTY_H

#include <string>
#include <map>
#include <vector>

namespace te{

	//typedef std::map<std::string, std::string> TilePropertyMap;	
	//typedef std::map<std::string, std::string> PropertyCollection;

	struct Property {
		std::string key;
		std::string value;
		
		int ToInt(){
			return atoi(value.c_str());
		}
		
		std::string ToString(){
			return value;
		}
		
		const char* ToCString(){
			return value.c_str();
		}
	};
	
	class PropertyCollection {
		private:
			std::vector<Property>				mProperties;
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