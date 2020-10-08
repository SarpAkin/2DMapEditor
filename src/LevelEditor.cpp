#include "LevelEditor.h"

#include <fstream>
#include <string>
#include <iostream>

#include "ClassParser.h"
#include "Tile.h"

typedef LevelEditor editor;

bool editor::OnUserCreate()
{
    //Loading The map
    //s = olc::Sprite("img/dirt.png");
    //sd = new olc::Decal(&s);
    nsTile::init();
    std::cout << "helloworld\n";
    std::string str;
    std::ifstream ifs = std::ifstream("level.txt");
    std::string img("img");
    nsTile::ImportFromString(str.begin(),0,img);
    /*
    if(ifs.is_open())
    {
        str = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        uint32_t size = ParseToClass<uint32_t>(str.begin());
        nsTile::ImportFromString(str.begin() + 4,0,img);
        ifs.close();
    }
    else
    {
        nsTile::ImportFromString(str.begin(),0,img);
    }
    */
    //Hotbar
    std::cout << nsTile::Tiledatas.size();
    std::cout << nsTile::dictionary.size();    
    /*
    int index = 0;
    for(auto& s : Hotbar)
    {
        s = Slot(nsTile::Tiledatas[index]);
        index++;
        if(index >= nsTile::Tiledatas.size())
            index = 0;
    }
    */
    //
    pivot = Vector2(ScreenHeight(),ScreenWidth());
    return true;
}

bool editor::OnUserUpdate(float fElapsedTime)
{
    std::cout << "hellowrodl";
    //Input
        //hotbar managment
    if(GetMouseWheel() > 0)
    {
        TileIndex++;
        int end = Hotbar.size() - 1;
        for(int i = 0;i < end;i++)
        {
            std::swap(Hotbar[i],Hotbar[i + 1]);
        }
        int index = (TileIndex + Hotbar.size()) % nsTile::Tiledatas.size();
        Hotbar[Hotbar.size() - 1] = Slot(nsTile::Tiledatas[index]);
        if(TileIndex >= nsTile::Tiledatas.size())
            TileIndex = 0;
    }
    if(GetMouseWheel() < 0)
    {
        TileIndex--;
        for(int i = Hotbar.size() - 2;i >= 0;i--)
        {
            std::swap(Hotbar[i],Hotbar[i + 1]);
        }
        int index = TileIndex % nsTile::Tiledatas.size();
        Hotbar[Hotbar.size() - 1] = Slot(nsTile::Tiledatas[index]);
        if(TileIndex < 0)
            TileIndex = nsTile::Tiledatas.size() - 1;
    }
    //PreRender
    //ClearBuffer(olc::BLANK);
    //Render
        //ChunkRender
    Chunk* CurrentChunk = FindChunk(Chunks,ToChunkCord(CameraCord.ToVector2Int()));
    if(CurrentChunk)
    {
        Vector2 InChunkCord = GetCamCord() - (CurrentChunk->pos * ChunkSize).ToVector2();

        for(int y = 0;y < ChunkSize * ChunkSize;y+=ChunkSize)
        {
            for(int x = 0;x < ChunkSize;x++)
            {
                DrawDecal(LocalCordToScreen(Vector2(x,y)+ InChunkCord),CurrentChunk->Tiles[y+ x].GetDecal());
            }
        }
    }
        //Hotbar Render
    //
    /*
    {
        int x = SlotDistance;
        int y = ScreenHeight() - (Slotsize + SlotDistance);
        for(int i = 0;i < Hotbar.size();i++)
        {
            //DrawSprite(olc::vi2d(x,y),&s);
            //DrawDecal(olc::vi2d(x,y),d);
            x += SlotDistance + Slotsize;
        }
    }
    */
    return true;
}

bool editor::OnUserDestroy()
{
    std::ofstream of = std::ofstream("level.txt");
    if(of.is_open())
    {
        of.flush();
        auto out = nsTile::exportToString();
        of << ParseToStream(out.second);
        of << out.first;
        of.close();
    }
    return true;
}