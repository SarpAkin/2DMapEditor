#include "Tile.h"

#include <filesystem>
#include <map>

#include "ClassParser.h"

namespace nsTile
{
    std::map<std::array<char,16>,Tile> dictionary = std::map<std::array<char,16>,Tile>();
    std::vector<Tiledata> Tiledatas = std::vector<Tiledata>();
}

Tile::Tile()
{
    id = 0;
}

Tile::Tile(int i)
{
    id = i;
}

Tile::Tile(const std::string& key)
{
    std::array<char,16> chars = ToCharArray(key);
        
    auto it = nsTile::dictionary.find(chars);
    if(it != nsTile::dictionary.end())
    {
        *this = it->second;
    }
    else
    {
        id = 0;
    }
}


Tile::Tile(std::array<char,16> chars)
{        
    auto it = nsTile::dictionary.find(chars);
    if(it != nsTile::dictionary.end())
    {
        *this = it->second;
    }
    else
    {
        id = 0;
    }
}

olc::Decal* Tile::GetDecal()
{
    return nsTile::Tiledatas[id].d;
}

Tiledata& Tile::GetTileData()
{
    return nsTile::Tiledatas[id];
}

Tiledata::Tiledata()
{
    s = new olc::Sprite(1,1);
    s->SetPixel(0,0,olc::BLANK);
    d = new olc::Decal(s);
}

Tiledata::Tiledata(std::string& path)
{
    s = new olc::Sprite(path);
    std::cout << path << std::endl;
    d = new olc::Decal(s);
}

Tiledata::~Tiledata()
{
    delete s;
    delete d;
}

void nsTile::init()
{
    dictionary.insert(std::pair(std::array<char,16>{'a','i','r'},Tile(0)));
    Tiledatas.push_back(Tiledata());
}

std::pair<std::string,int> nsTile::exportToString()
{
    std::vector<std::pair<std::array<char,16>,Tile>> vec;
    vec.reserve(Tiledatas.size() - 1);
    for(auto it = ++dictionary.begin();it != dictionary.end();it++)
    {
        vec.push_back(*it);
    }
    return std::pair(ParseVectorToStream(vec),vec.size());
}

std::string::iterator nsTile::ImportFromString(std::string::iterator str,int size,std::string& path)
{
    Tiledatas.reserve(size + 1);
    std::vector<std::pair<std::array<char,16>,std::string>> paths;
    for(auto& file : std::filesystem::directory_iterator(path))
    {
        if(!file.is_directory())
        {
            std::string str = file.path().filename().string();
            paths.emplace_back(ToCharArray(str),file.path().string());
        }
    }
    /*
    if(size != 0)
    {
        std::vector<std::pair<std::array<char,16>,Tile>> vec = ParseToClassVector<std::pair<std::array<char,16>,Tile>>(str,size);
        for(auto itv = vec.begin();itv != vec.end();itv++)
        {
            for(auto itp = paths.begin();itp != paths.end();itp++)
            {
                if(itv->first == itp->first)
                {
                    dictionary.insert(std::pair(itv->first,Tile(Tiledatas.size())));//may have somelogic error
                    Tiledatas.push_back(Tiledata(itp->second));
                    paths.erase(itp);
                    vec.erase(itv);
                    itv--;
                    itp--;
                }
            }
        }
        
        if(vec.size() == 0)
        {
            std::cout << "assets couldn't found exiting!\n";
            exit(EXIT_FAILURE);
        }
    }
    */
    for(auto& p : paths)
    {
        std::cout << "debug\n";
        dictionary.insert(std::pair(p.first,Tile(Tiledatas.size())));
        std::cout << p.second + " jj" << std::endl;
        Tiledata td(p.second);
        std::cout << "debugnnn\n";
        Tiledatas.push_back(td);
        std::cout << "böyle programın\n";
    }
    return str + sizeof(std::vector<std::pair<std::array<char,16>,Tile>>) * size;
    return str + 0;
}