#include "block.h"
#include "vector2i.h"


class LBlock :public block {
public:
    LBlock() {
        id = 1;
        cells[0] = { vector2i(0,2), vector2i(1,0), vector2i(1,1), vector2i(1,2) };
        cells[1] = { vector2i(0,1), vector2i(1,1), vector2i(2,1), vector2i(2,2) };
        cells[2] = { vector2i(1,0), vector2i(1,1), vector2i(1,2), vector2i(2,0) };
        cells[3] = { vector2i(0,0), vector2i(0,1), vector2i(1,1), vector2i(2,1) };
        Move(0, 3);
    }
};
class JBlock :public block {
public:
    JBlock() {
        id = 2;
        cells[0] = { vector2i(0,0), vector2i(1,0), vector2i(1,1), vector2i(1,2) };
        cells[1] = { vector2i(0,1), vector2i(0,2), vector2i(1,1), vector2i(2,1) };
        cells[2] = { vector2i(1,0), vector2i(1,1), vector2i(1,2), vector2i(2,2) };
        cells[3] = { vector2i(0,1), vector2i(1,1), vector2i(2,0), vector2i(2,1) };
        Move(0, 3);
    }
};
class IBlock :public block {
public:
    IBlock() {
        id = 3;
        cells[0] = { vector2i(1,0), vector2i(1,1), vector2i(1,2), vector2i(1,3) };
        cells[1] = { vector2i(0,2), vector2i(1,2), vector2i(2,2), vector2i(3,2) };
        cells[2] = { vector2i(2,0), vector2i(2,1), vector2i(2,2), vector2i(2,3) };
        cells[3] = { vector2i(0,1), vector2i(1,1), vector2i(2,1), vector2i(3,1) };
        Move(0, 3);
    }
};
class OBlock :public block {
public:
    OBlock() {
        id = 4;
        cells[0] = { vector2i(0,0), vector2i(0,1), vector2i(1,0), vector2i(1,1) };
        cells[1] = { vector2i(0,0), vector2i(0,1), vector2i(1,0), vector2i(1,1) };
        cells[2] = { vector2i(0,0), vector2i(0,1), vector2i(1,0), vector2i(1,1) };
        cells[3] = { vector2i(0,0), vector2i(0,1), vector2i(1,0), vector2i(1,1) };
        Move(0, 4);
    }
};
class SBlock :public block {
public:
    SBlock() {
        id = 5;
        cells[0] = { vector2i(0,1), vector2i(0,2), vector2i(1,0), vector2i(1,1) };
        cells[1] = { vector2i(0,1), vector2i(1,1), vector2i(1,2), vector2i(2,2) };
        cells[2] = { vector2i(1,1), vector2i(1,2), vector2i(2,0), vector2i(2,1) };
        cells[3] = { vector2i(0,0), vector2i(1,0), vector2i(1,1), vector2i(2,1) };
        Move(0, 3);
    }
};
class ZBlock :public block {
public:
    ZBlock() {
        id = 6;
        cells[0] = { vector2i(0,0), vector2i(0,1), vector2i(1,1), vector2i(1,2) };
        cells[1] = { vector2i(0,2), vector2i(1,1), vector2i(1,2), vector2i(2,1) };
        cells[2] = { vector2i(1,0), vector2i(1,1), vector2i(2,1), vector2i(2,2) };
        cells[3] = { vector2i(0,1), vector2i(1,0), vector2i(1,1), vector2i(2,0) };
        Move(0, 3);
    }
};
class TBlock :public block {
public:
    TBlock() {
        id = 7;
        cells[0] = { vector2i(0,1), vector2i(1,0), vector2i(1,1), vector2i(1,2) };
        cells[1] = { vector2i(0,1), vector2i(1,1), vector2i(1,2), vector2i(2,1) };
        cells[2] = { vector2i(1,0), vector2i(1,1), vector2i(1,2), vector2i(2,1) };
        cells[3] = { vector2i(0,1), vector2i(1,0), vector2i(1,1), vector2i(2,1) };
        Move(0, 3);
    }
};