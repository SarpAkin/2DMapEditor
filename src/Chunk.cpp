#include "Chunk.h"

Chunk::Chunk()
{
    NorthChunk = NULL;
    SouthChunk = NULL;
    WestChunk = NULL;
    EastChunk = NULL;
}

Chunk::Chunk(const std::vector<Chunk*>& Chunks,Vector2Int pos)
{
    
}

Chunk* FindChunk(const std::vector<Chunk*>& Chunks,Vector2Int pos)
{
    for(auto* c : Chunks)
    {
        if(c->pos == pos)
        {
            return c;
        }
    }
    return NULL;
}