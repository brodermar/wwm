#include "model.h"

const std::string Model::EXIT_EXP = "exit";
const std::string Model::QUIT_GAME_EXP = "quit";
const std::string Model::START_GAME_EXP = "start";

Model::Model()
{
    running = true;
    activeGame = nullptr;
    qDebug() << "initialized new Model" << endl;
}

Model::~Model()
{
    delete activeGame;
    qDebug() << "~Model() called" << endl;
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
    qDebug() << "quitGame() called" << endl;
    mutex.lock();
    delete activeGame;
    activeGame = nullptr;
    mutex.unlock();
}

void Model::startNewGame()
{
    qDebug() << "startNewGame() called" << endl;
    mutex.lock();
    delete activeGame;
    activeGame = Game::startNewGame();
    mutex.unlock();
}

bool Model::isProgramRunning()
{
    bool value;
    mutex.lock();
    value = running;
    mutex.unlock();
    return value;
}

void Model::terminateProgram()
{
    qDebug() << "terminateProgram() called" << endl;
    mutex.lock();
    running = false;
    mutex.unlock();
}
