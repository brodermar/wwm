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
    return activeGame;
}

void Model::quitGame()
{
    delete activeGame;
    activeGame = nullptr;
}

void Model::startNewGame()
{
    delete activeGame;
    activeGame = Game::startNewGame();
}

bool Model::isProgramRunning()
{
    return running;
}

void Model::terminateProgram()
{
    running = false;
}
