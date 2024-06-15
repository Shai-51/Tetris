#pragma once

#include <vector>
#include <map>

#include "vector2i.h"
#include "grid.h"

/*
    the main class of the tetris blocks. 
*/

class block
{
private:
    int cellSize;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
    int rotationState;
public:
    block();
    void Draw();
    void Move(int row, int colunm);

    std::vector<vector2i> GetCellPositions();

    std::map<int, std::vector<vector2i>> cells;
    void rotate();
    int id; // for the color number at within the vector
    void undoRotation(); // if the block will get out of scrren when it is rotating
};

