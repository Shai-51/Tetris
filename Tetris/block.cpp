#include "block.h"
#include "color.h"
block::block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    columnOffset = 0;
    rowOffset = 0;
    id = 0;
}
void block::Draw() {
    std::vector<vector2i> tiles = GetCellPositions();
    for (vector2i& item : tiles) {
        DrawRectangle(item.column * cellSize, item.row * cellSize, cellSize, cellSize, colors[id]);
    }
}

void block::Move(int row, int colunm)
{
    columnOffset += colunm;
    rowOffset += row;

}
std::vector<vector2i> block::GetCellPositions()
{
    std::vector<vector2i> tiles = cells[rotationState];
    std::vector<vector2i> movedTiles;
    for (vector2i item : tiles)
    {
        vector2i newPos = vector2i(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void block::rotate()
{
    rotationState++;
    if (rotationState == cells.size())
    {
     rotationState = 0;
     }

}
void block::undoRotation() {
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}