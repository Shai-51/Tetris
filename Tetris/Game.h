#pragma once

#include <vector>
#include <random>

#include "grid.h"
#include "blocks.cpp"

/*
	main class of the game. control all of the game rules.
*/

class Game
{
public: 
	Game();
	void Run();
private:
	grid Grid;
	std::vector<block> getAllBlocks();
	void draw();
	bool timer(double interval);
	void handleUserInput();
	void MoveBlockDown();
	std::vector<block> blocks;
	block getRandomBLock();
	block currentBlock;
	block nextBlock;
	bool isBlockOutside();
	double lastUpdateTime = 0;
	void lockBlock();
	bool blockFits();
	bool GameOver;
	void reset();
};

