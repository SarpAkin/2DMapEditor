#ifndef Chunk_H
#define Chunk_H

#include <array>
#include <vector>

#include "Tile.h"
#include "Vector2Int.h"

const int ChunkSize = 32;

inline Vector2Int ToChunkCord(Vector2Int pos)
{
    return Vector2Int(pos.x < 0 ? (pos.x / ChunkSize) - 1 : pos.x / ChunkSize,pos.y < 0 ? (pos.y / ChunkSize) - 1 : pos.y / ChunkSize);
}

class Chunk
{
    public://variables
    Chunk* NorthChunk;//y-
    Chunk* SouthChunk;//y+
    Chunk* WestChunk; //x-
    Chunk* EastChunk; //x+ 
    Vector2Int pos;
    std::array<Tile,ChunkSize * ChunkSize> Tiles;
    public://functions
    Chunk();
    Chunk(const std::vector<Chunk*>& Chunks,Vector2Int pos);
};

Chunk* FindChunk(const std::vector<Chunk*>& Chunks,Vector2Int pos);

#endif