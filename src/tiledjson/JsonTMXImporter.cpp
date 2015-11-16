// JsonTMXImporter.cpp
//
// Dan Alexander 08/29/14
// Copyright(c) 2014
//
/* JsonTMXImporter
 *
 * This class handles importing levels from
 * TMX json files.
 */
 
#include "JsonTMXImporter.hpp"
#include <fstream>
#include <iostream>

#include "json/json.h"
#include "Property.hpp"

namespace te
{

JsonTMXImporter::JsonTMXImporter()
: mMapDetailsLoaded(false)
{
}

JsonTMXImporter::~JsonTMXImporter()
{
}

bool JsonTMXImporter::Load(const char* filename){
	return LoadTMXJson(filename);
}

bool JsonTMXImporter::LoadTMXJson(const char* filename){

	Json::Value root;
	Json::Reader reader;

	std::ifstream filestream(filename, std::ifstream::binary);
	bool successful = reader.parse(filestream, root, false);
	if (!successful){
		printf("Error loading map file.\nError: %s\n", reader.getFormattedErrorMessages().c_str());
		throw;
	}
	
	mMapDetails.Width = root["width"].asInt();
	mMapDetails.Height = root["height"].asInt();
	mMapDetails.TileWidth = root["tilewidth"].asInt();
	mMapDetails.TileHeight = root["tileheight"].asInt();
	
	// Get Map Properties
	const Json::Value mapProperties = root["properties"];

	for (Json::ValueIterator itr = mapProperties.begin(); itr != mapProperties.end(); itr++)
	{
		std::string key = itr.key().asString();
		std::string value = mapProperties[key].asString();
		
		mMapDetails.MapProperties[key] = value;
	}
	
	// Get Tileset details
	for (int i = 0; i < root["tilesets"].size(); ++i) {
        Json::Value tileset = root["tilesets"][i];
			
		TMXTilesetDetails t;
		t.Name = tileset["name"].asString();
		
		t.ImagePath = tileset["image"].asString();
		t.ImageWidth = tileset["imagewidth"].asInt();
		t.ImageHeight = tileset["imageheight"].asInt();
		t.Margin = tileset["margin"].asInt();
		t.Spacing = tileset["spacing"].asInt();
		t.TileHeight = tileset["tileheight"].asInt();
		t.TileWidth = tileset["tilewidth"].asInt();
		t.FirstGID = tileset["firstgid"].asInt();
		
		// Get Tile Properties
        Json::Value tilesWithProperties = tileset["tileproperties"];
        int tpi = 0;

        for (Json::ValueIterator propitr = tilesWithProperties.begin(); propitr != tilesWithProperties.end(); propitr++){
			std::string key = propitr.key().asString();
            int tpk = t.FirstGID + atoi(key.c_str());

			Json::Value tileproperties = tilesWithProperties[key];

            for (Json::ValueIterator itr = tileproperties.begin(); itr != tileproperties.end(); ++itr)
            {
                std::string propertyKey = itr.key().asString();
                std::string value = tileproperties[propertyKey].asString();

                mMapDetails.AllTilesetProperties[tpk][propertyKey] = value;
                t.TileProperties[tpk].set(propertyKey, value);
            }

        }
		
		mMapDetails.Tilesets.push_back(t);
		
	}
	
	// Get Layers
	for (int i = 0; i < root["layers"].size(); ++i){
		TMXLayer l;
		
        Json::Value layerData = root["layers"][i];
		
		if (layerData["type"] == "tilelayer"){
			l.Type = TMXLayer_Tile;
			l.Name = layerData["name"].asString();
			
			l.Width = layerData["width"].asInt();
			l.Height = layerData["height"].asInt();
			l.X = layerData["x"].asInt();
			l.Y = layerData["y"].asInt();
			l.Opacity = layerData["opacity"].asFloat();
			
			for (int j = 0; j < layerData["data"].size(); ++j){
				l.Data.push_back(layerData["data"][j].asInt());
			}
			
		}
		else if (layerData["type"] == "objectgroup"){
			l.Type = TMXLayer_Object;
			
			l.Name = layerData["name"].asString();
			
			for (int j = 0; j < layerData["objects"].size(); ++j){
				TMXObject o;

                Json::Value objectData = layerData["objects"][j];
				
				o.Name = objectData["name"].asString();
				o.Type = objectData["type"].asString();
				o.Height = objectData["height"].asInt();
				o.Width = objectData["width"].asInt();
				o.X = objectData["x"].asFloat();
				o.Y = objectData["y"].asFloat();

				if (objectData.isMember("polyline")){
					o.Kind = TMXObject_Polyline;
					
                    Json::Value polylineData = objectData["polyline"];
					
					for (unsigned int pi = 0; pi < polylineData.size(); ++pi){
						const Json::Value& point = polylineData[pi];
						TMXPoint line_point;
						line_point.x = point["x"].asFloat();
						line_point.y = point["y"].asFloat();
						o.polyline.points.push_back(line_point);
					}
				};

				const Json::Value& objectProperties = objectData["properties"];

				for (Json::ValueIterator itr = objectProperties.begin(); itr != objectProperties.end(); ++itr)
				{
					std::string key = itr.key().asString();
					std::string value = objectProperties[key].asString();
					
					o.Properties[key] = value;
				}
				
				l.Objects.push_back(o);
			}
		}
		else if (layerData["type"] == "imagelayer"){
			l.Type = TMXLayer_Image;
			
			l.Name = layerData["name"].asString();
			l.Image = layerData["image"].asString();
			
			l.Width = layerData["width"].asInt();
			l.Height = layerData["height"].asInt();
			l.X = layerData["x"].asInt();
			l.Y = layerData["y"].asInt();
		}
		mMapDetails.Layers.push_back(l);
	}
	
	// return success
	return true;
}

std::vector<MapLayer*> JsonTMXImporter::GetLayers(){
	std::vector<MapLayer*> layers;
	
	for (TMXLayer& tmxlayer : mMapDetails.Layers){
		if (tmxlayer.Type == TMXLayer_Tile){
			MapTileLayer* layer = new MapTileLayer();
			layer->SetTileData(tmxlayer.Width, tmxlayer.Height, tmxlayer.Data);
			layer->setX(tmxlayer.X);
			layer->setY(tmxlayer.Y);
			layer->setName(tmxlayer.Name);
			layer->setOpacity(tmxlayer.Opacity);
		
			layers.push_back(layer);
		}
		else if (tmxlayer.Type == TMXLayer_Object){
			MapObjectGroup* group = new MapObjectGroup();
			group->setName(tmxlayer.Name);
			
			for (unsigned int j = 0; j < tmxlayer.Objects.size(); ++j){
				MapObject obj;
				obj.SetName(tmxlayer.Objects[j].Name);
				obj.SetWidth(tmxlayer.Objects[j].Width);
				obj.SetHeight(tmxlayer.Objects[j].Height);
				obj.SetX(tmxlayer.Objects[j].X);
				obj.SetY(tmxlayer.Objects[j].Y);
				obj.SetKind((MapObjectKind)tmxlayer.Objects[j].Kind);
				
				for (auto& kv : tmxlayer.Objects[j].Properties){
					obj.SetProperty(kv.first, kv.second);
				}
				
				// polyline
				if (obj.GetKind() == MapObject_Polyline){
					Polyline pline;
					for (unsigned int k = 0; k < tmxlayer.Objects[j].polyline.points.size(); ++k){
						PolylinePoint pp;
						pp.x = tmxlayer.Objects[j].polyline.points[k].x;
						pp.y = tmxlayer.Objects[j].polyline.points[k].y;
						pline.points.push_back(pp);
					}
					obj.SetPolyLine(pline);
				}
				
				group->AddObject(obj);
			}
			
			layers.push_back(group);
		}
		else if (tmxlayer.Type == TMXLayer_Image){
			MapImageLayer* layer = new MapImageLayer(tmxlayer.Name, tmxlayer.Image, tmxlayer.X, tmxlayer.Y, tmxlayer.Width, tmxlayer.Height);
			layer->setOpacity(tmxlayer.Opacity);
			layers.push_back(layer);
		}
	}
	
	return layers;
}

TilePropertyGidMap JsonTMXImporter::GetTileProperties() {
	TilePropertyGidMap all_properties;
	
	for (auto& kv : mMapDetails.AllTilesetProperties){
		//all_properties[kv.first] = kv.second;
//		std::cout << kv.first << std::endl;
		PropertyCollection collect;
		for (auto& props : kv.second){
			collect.set(props.first, props.second);
		}
		all_properties[kv.first] = collect;
	}
	
	return all_properties;
}

std::vector<MapTileSet> JsonTMXImporter::GetTileSets(){
	std::vector<MapTileSet> sets;
	
	for (unsigned int i = 0; i < mMapDetails.Tilesets.size(); ++i){
		
		TMXTilesetDetails details = mMapDetails.Tilesets[i];
		
		MapTileSet set;
		set.setName(details.Name);
		set.setFilePath(details.ImagePath);
		set.setImageHeight(details.ImageHeight);
		set.setImageWidth(details.ImageWidth);
		set.setFirstGID(details.FirstGID);
		set.setMargin(details.Margin);
		set.setSpacing(details.Spacing);
		set.setTileHeight(details.TileHeight);
		set.setTileWidth(details.TileWidth);
		
		// wrong
		set.setLastGID(details.FirstGID + 1);
		
		sets.push_back(set);
	}
	
	return sets;
}

int JsonTMXImporter::GetMapWidth(){
	return mMapDetails.Width;
}

int JsonTMXImporter::GetMapHeight(){
	return mMapDetails.Height;
}
/*
std::vector<Tile> JsonTMXImporter::GetTiles(){
	
	std::vector<Tile> tiles;
	
	std::cout << "Creating tiles." << std::endl;
	
	for (int i = 0; i < mMapDetails.Width * mMapDetails.Height; ++i){
		Tile t;
		
		int x = i / mMapDetails.Width;
		int y = i % mMapDetails.Width;			
		
		// get drawable layer data
		for (unsigned int l = 0; l < mMapDetails.Layers.size(); ++l){
			if (x >= mMapDetails.Layers[l].X && x < mMapDetails.Layers[l].X + mMapDetails.Layers[l].Width
				&& y >= mMapDetails.Layers[l].Y && y < mMapDetails.Layers[l].Y + mMapDetails.Layers[l].Height){
					int li = mMapDetails.Layers[l].Width * y + x;
					t.AddLayer(mMapDetails.Layers[l].Data[li]);
				}
		}
		
		// get tile meta data
		if (x >= mMapDetails.MetaLayer.X && x < mMapDetails.MetaLayer.X + mMapDetails.MetaLayer.Width
				&& y >= mMapDetails.MetaLayer.Y && y < mMapDetails.MetaLayer.Y + mMapDetails.MetaLayer.Height){
					
					int li = mMapDetails.MetaLayer.Width * y + x;
					int gid = mMapDetails.MetaLayer.Data[li];
					
					// first check if the gid is 0 (empty tile) or if there are no properties for it.
					if (gid > 0 && mMapDetails.AllTilesetProperties.find(gid) != mMapDetails.AllTilesetProperties.end()){
						
						// iterate through the key/value pairs in the properties.
						for(std::map<std::string, std::string>::iterator it = mMapDetails.AllTilesetProperties[gid].begin(); it != mMapDetails.AllTilesetProperties[gid].end(); ++it) {
							t.AddProperty(it->first, it->second);
						}
						
					}
				}
				
		// save the tile
		tiles.push_back(t);
	}
	
	return tiles;
}

std::vector<Tileset> JsonTMXImporter::GetTilesets(){
	
	std::vector<Tileset> sets;
	
	for (unsigned int i = 0; i < mMapDetails.Tilesets.size(); ++i){
		Tileset set;
		set.Name = mMapDetails.Tilesets[i].Name;
		set.FirstGID = mMapDetails.Tilesets[i].FirstGID;
		set.ImageHeight = mMapDetails.Tilesets[i].ImageHeight;
		set.ImageWidth = mMapDetails.Tilesets[i].ImageWidth;
		set.ImagePath = mMapDetails.Tilesets[i].ImagePath;
		set.Margin = mMapDetails.Tilesets[i].Margin;
		set.Spacing = mMapDetails.Tilesets[i].Spacing;
		set.TileHeight = mMapDetails.Tilesets[i].TileHeight;
		set.TileWidth = mMapDetails.Tilesets[i].TileWidth;		
		set.TilesWide = set.ImageWidth / set.TileWidth;
		set.TilesHigh = set.ImageHeight / set.TileHeight;
		
		sets.push_back(set);
	}
	
	return sets;
}

std::vector<MapEntity> JsonTMXImporter::GetObjects(){
	std::vector<MapEntity> objects;
	
	for (unsigned int i = 0; i < mMapDetails.ObjectGroups.size(); ++i){
		for (unsigned int j = 0; j < mMapDetails.ObjectGroups[i].Objects.size(); ++j){
			MapEntity e;
			e.SetName(mMapDetails.ObjectGroups[i].Objects[j].Name);
			e.SetType(mMapDetails.ObjectGroups[i].Objects[j].Type);
			e.SetProperty(mMapDetails.ObjectGroups[i].Objects[j].Properties);
			e.setPosition(sf::Vector2f(mMapDetails.ObjectGroups[i].Objects[j].X, mMapDetails.ObjectGroups[i].Objects[j].Y));
			
			e.SetSize(sf::Vector2i(mMapDetails.ObjectGroups[i].Objects[j].Width, mMapDetails.ObjectGroups[i].Objects[j].Height));
			
			Polygon p;
			p.AddPoint(e.getPosition());
			p.AddPoint(e.getPosition() + sf::Vector2f(mMapDetails.ObjectGroups[i].Objects[j].Width, 0));
			p.AddPoint(e.getPosition() + sf::Vector2f(mMapDetails.ObjectGroups[i].Objects[j].Width, mMapDetails.ObjectGroups[i].Objects[j].Height));
			p.AddPoint(e.getPosition() + sf::Vector2f(0, mMapDetails.ObjectGroups[i].Objects[j].Height));
			
			e.SetPolygon(p);
			
			objects.push_back(e);
		}
	}
	
	return objects;
}*/

std::map<std::string, std::string> JsonTMXImporter::GetMapProperties(){
	return mMapDetails.MapProperties;
}


}