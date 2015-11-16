## Introduction
C++11 [Tiled](http://www.mapeditor.org/) map loader that uses the JSON export format
instead of the TMX.

tiledjson is *not* a Tiled map renderer, nor is it built with any specific framework,
library, or engine in mind.

What it *is* is an object-oriented approach to loading and accessing Tiled maps that
are in the JSON format.

## Using tiledjson in your project

The recommended approach to integrating tiledjson in your project is to include
the source and header files in your project, and compile and build as you would
any other source file.

The only external dependency for tiledjson is [JsonCpp](https://github.com/open-source-parsers/jsoncpp).
JsonCpp is used by the `JsonTMXImporter` class to parse the JSON files. Using
JsonCpp's [amalgamated source and header](https://github.com/open-source-parsers/jsoncpp#generating-amalgamated-source-and-header) is very simple and the recommended approach.

## Quick Start
Start by exporting your map's TMX file to JSON. In Tiled, goto:

```
- File
  - Export As (Ctrl-E)
```

And select `json map files (*.json)` from the "Save as type" drop down. You will also
need to make sure you have the map's property "Tile Layer Format" set to "CSV". This
is because zlib compression is not supported; this will hopefully be unnecessary in
the near future.

Using tiledjson is fairly simple:

```
tiledjson::TMXMap theMap("path/to/level.json");
```

That will attempt to open and parse the JSON file and load the data into the `TMXMap`.

## Features

- Loads Tiled maps that are exported in the JSON format
- Layer support:
  - Tile layers
  - Object layers
  - Image layers
- Property Support:
  - Map
  - Layer
  - Object
  - Tile
- Objects:
  - Rectangle
  - Polyline

## Roadmap
- zlib support for tile layers
- Better way to handle properties
- `Object: Ellipse` support

## License
See the `LICENSE` file for details. In summary, tiledjson is licensed under the
MIT license, or public domain if desired and recognized in your jurisdiction.