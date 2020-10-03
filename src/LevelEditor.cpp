#include "LevelEditor.h"

#include <fstream>
#include <string>
#include <iostream>

#include "ClassParser.h"

typedef LevelEditor editor;

bool editor::OnUserCreate()
{
    nsTile::init();
    std::string str;
    std::ifstream ifs = std::ifstream("level.txt");
    std::string img("img");
    if(ifs.is_open())
    {
        str = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        uint32_t size = ParseToClass<uint32_t>(str.begin());
        nsTile::ImportFromString(str.begin() + 4,size,img);
    }
    else
    {
        nsTile::ImportFromString(str.begin(),0,img);
    }
    
    
    //nsTile::ImportFromString();
    return true;
}

bool editor::OnUserUpdate(float fElapsedTime)
{

    return true;
}

bool editor::OnUserDestroy()
{

    return true;
}

