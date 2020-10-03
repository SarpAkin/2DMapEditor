#ifndef Tile_H
#define Tile_H

#include <iostream>
#include <vector>
#include <array>

#include "../dependencies/olcPixelGameEngine.h"

struct Tiledata
{
    public:
    olc::Sprite* s;
    olc::Decal*  d;
    public:
    Tiledata();
    Tiledata(std::string& path);
    ~Tiledata();
};

struct Tile
{   
    public:
    uint16_t id;
    public:
    Tile();
    Tile(int i);
    Tile(const std::string&);
    Tile(std::array<char,16> chars);
    Tiledata& GetTileData();
    olc::Decal* GetDecal();
};

namespace nsTile
{
    void init();
    std::pair<std::string,int> exportToString();
    std::string::iterator ImportFromString(std::string::iterator,int size,std::string& path);
}

inline std::array<char,16> ToCharArray(const std::string& str)
{
    std::array<char,16> chars;
    for(int i = 0;i < str.length() && i < chars.size();i++)
    {
        chars[i] = str[i];
    }
    return chars;
}

#endif