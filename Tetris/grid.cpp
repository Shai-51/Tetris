#include "grid.h"

grid::grid()
{
    cellSize = 30;
    rows = 20;
    colums = 10;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < colums; c++)
        {
            Grid[r][c] = 0;
        }

    }
    colors = GetCellColors();

}
void grid::debug() {
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < colums; c++) {
            std::cout << " " << Grid[c][r];
        }
        std::cout << std::endl;
    }

}

bool grid::isCellOutside(int row, int column)
{
    if (row >= 0 and row < rows and column >= 0 and column < colums)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool grid::isCellEmpty(int row, int column)
{
    if (Grid[row][column] == 0)
    {
        return true;
    }
    return false;
}



void grid::Draw() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < colums; c++)
        {
            int cellNum = Grid[r][c];
            DrawRectangle(c * cellSize, r * cellSize, cellSize, cellSize, colors[cellNum]);
        }

    }
}

