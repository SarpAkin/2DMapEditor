#pragma once

#include "../dependencies/olcPixelGameEngine.h"
#include "Tile.h"
class LevelEditor : protected olc::PixelGameEngine
{
    private://vars

    public://func
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;
};