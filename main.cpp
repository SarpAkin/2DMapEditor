#include <iostream>

#include "src/LevelEditor.h"

int main()
{
    LevelEditor editor;
    if(editor.Construct(1280,720,1,1))
        editor.Start();
}