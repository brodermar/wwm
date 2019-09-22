#include "game.h"

Game::Game()
{
    roundCounter = 0;
    curReward
}

Game::~Game()
{

}

bool Game::isFinished()
{
    return finished;
}

int Game::getCurReward()
{
    return *curReward;
}

int Game::getRoundCount()
{

}

bool Game::evaluateAnswer(std::string answer)
{

}

Question* Game::getCurQuestion()
{

}

Game* Game::newGame()
{
    return new Game();
}
