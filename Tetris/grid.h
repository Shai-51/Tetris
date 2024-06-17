#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include "color.h"
class grid
{
private:
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowsDown(int row, int rowsNUm);
    int rows;
    int colums;
    int cellSize;
    std::vector<Color> colors;
public:
    grid();
    void reset();
    void Draw();
    int Grid[20][10];
    void debug();
    bool isCellOutside(int row, int column);
    bool isCellEmpty(int row, int column);
    int clearFullRows();
};

