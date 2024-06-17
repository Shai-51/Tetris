#include "Game.h"

Game::Game()
{

	Grid = grid();
	blocks = getAllBlocks();
	currentBlock = getRandomBLock();
	nextBlock = getRandomBLock();
	GameOver = false;

}

void Game::Run()
{
	BeginDrawing();
	ClearBackground(BLACK);
	handleUserInput();
	if (!GameOver)
	{
		if (timer(0.1))
		{
			MoveBlockDown();
		}
	}
	draw();
	EndDrawing();
}

std::vector<block> Game::getAllBlocks()
{

	return {IBlock(), LBlock(), JBlock(), OBlock(), ZBlock(), SBlock(), TBlock()};
}

block Game::getRandomBLock()
{
	if (blocks.empty()) {
		blocks = getAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	block Block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return Block;
}


bool Game::isBlockOutside()
{
	std::vector<vector2i> tiles = currentBlock.GetCellPositions();
	for (vector2i t: tiles)
	{
		if (Grid.isCellOutside(t.row, t.column)) {
			return true;
		}
	}
	return false;
}

void Game::lockBlock()
{
	std::vector<vector2i> tiles = currentBlock.GetCellPositions();
	for (vector2i t: tiles)
	{
		Grid.Grid[t.row][t.column] = currentBlock.id;
	}

	currentBlock = nextBlock;
	if(blockFits() == false) {
		GameOver = true;
	}
	nextBlock = getRandomBLock();
	Grid.clearFullRows();
}

bool Game::blockFits()
{
	std::vector<vector2i> tiles = currentBlock.GetCellPositions();
	for (vector2i t : tiles)
	{
		if (Grid.isCellEmpty(t.row, t.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::reset()
{
	Grid.reset();
	blocks = getAllBlocks();
	currentBlock = getRandomBLock();
	nextBlock = getRandomBLock();
}

void Game::handleUserInput()
{
	float keyDelay = 0.08;
	int keyPressed = GetKeyPressed();
	if (GameOver && keyPressed != 0)
	{
		GameOver = false;
		reset();
	}
	if (IsKeyDown(KEY_LEFT)) {
		currentBlock.Move(0, -1);
		if (isBlockOutside() || !blockFits())
		{
			currentBlock.Move(0, 1);
		}
		WaitTime(keyDelay);
	}
	if (IsKeyDown(KEY_RIGHT)) {
		currentBlock.Move(0, 1);		
		if (isBlockOutside() || !blockFits())
		{
			currentBlock.Move(0, -1);
		}
		WaitTime(keyDelay);
	}
	if (IsKeyDown(KEY_DOWN)) {
		currentBlock.Move(1, 0);
		if (isBlockOutside() || !blockFits())
		{
			currentBlock.Move(-1, 0);	
		}
		WaitTime(keyDelay);
	}
	if (IsKeyPressed(KEY_UP))
	{
		currentBlock.rotate();
		if (isBlockOutside() || !blockFits())
		{
			currentBlock.undoRotation();
		}
	}
}

void Game::MoveBlockDown()
{
	currentBlock.Move(1, 0);
	if (isBlockOutside() || blockFits() == false)
	{
		currentBlock.Move(-1, 0);
		lockBlock();
	}
}


void Game::draw() {
	Grid.Draw();
	currentBlock.Draw();
}
bool Game::timer(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}
