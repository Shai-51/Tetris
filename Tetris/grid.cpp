#include "grid.h"

bool grid::isRowFull(int row)
{
    for (int c = 0; c < colums; c++)
    {
        if (Grid[row][c] == 0) {
            return false;
        }
    }
    return true;
}

void grid::clearRow(int row)
{
    for (int c = 0; c < colums; c++)
    {
        Grid[row][c] = 0;
    }
}

void grid::moveRowsDown(int row, int rowsNum)
{
    for (int c = 0; c < colums; c++)
    {
        Grid[row + rowsNum][c] = Grid[row][c];
        Grid[row][c] = 0;
    }
}

int grid::clearFullRows()
{
    int completed = 0;
    for ( int r = rows-1; r >= 0; r--)
    {
        if (isRowFull(r)) {
            clearRow(r);
            completed++;
        }
        else if (completed > 0)
        {
            moveRowsDown(r, completed);
        }
    }
    return completed;
}

grid::grid()
{
    cellSize = 30;
    rows = 20;
    colums = 10;
    colors = GetCellColors();
    reset();
}
void grid::reset()
{

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < colums; c++)
        {
            Grid[r][c] = 0;
        }
    }
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

