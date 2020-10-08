#pragma once

#include <vector>

#include "../dependencies/olcPixelGameEngine.h"
#include "Tile.h"
#include "Chunk.h"
#include "Vector2.h"

const int Slotsize = 32;
const int SlotDistance = 12;
struct Slot
{
	olc::Decal* dec;
	olc::vi2d size = olc::vi2d(1,1);
	inline Slot()
	{

	}
	inline Slot(const Tiledata& t)
	{
		dec = t.d;
		size = olc::vi2d(Slotsize / t.d->sprite->width,Slotsize / t.d->sprite->width);
	}
};

class LevelEditor : public olc::PixelGameEngine
{
    private://vars
    Vector2 CameraCord;
	Vector2 pivot;
	std::vector<Chunk*> Chunks;
	std::array<Slot,3> Hotbar;
	int TileIndex = 0;
	float TileSize = 32.0f;
	olc::Sprite s;
	olc::Decal *d;

    public://func
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;
    public://inlines
    inline Vector2 GetCamCord()
	{
		return CameraCord - pivot / TileSize;
	}
	inline Vector2 ScreenCordToLocal(int x,int y)
	{
		return GetCamCord() + Vector2(x,y) / TileSize;
	}
	inline olc::vi2d LocalCordToScreen(Vector2 v)
	{
		Vector2 final = (v - GetCamCord()) * TileSize;
		return olc::vi2d((int32_t)final.x,(int32_t)final.y);
	}
};