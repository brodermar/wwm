#include "model.h"

const std::string Model::EXIT_EXP = "exit";
const std::string Model::QUIT_GAME_EXP = "quit";
const std::string Model::START_GAME_EXP = "start";

Model::Model()
{
    running = true;
    activeGame = nullptr;
}

Model::~Model()
{
    delete activeGame;
}

Game* Model::getCurrentGame()
{
    Game* game = nullptr;
    mutex.lock();
    game = activeGame;
    mutex.unlock();
    return game;
}

void Model::quitGame()
{
    mutex.lock();
    delete activeGame;
    activeGame = nullptr;
    mutex.unlock();
}

void Model::startNewGame()
{
    mutex.lock();
    delete activeGame;
    activeGame = Game::startNewGame();
    mutex.unlock();
}

bool Model::isProgramRunning()
{
    bool isRunning = false;
    mutex.lock();
    isRunning = running;
    mutex.unlock();
    return isRunning;
}

void Model::terminateProgram()
{
    mutex.lock();
    running = false;
    mutex.unlock();
}
