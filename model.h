#ifndef MODEL_H
#define MODEL_H

#pragma once

#include <gameobservable.h>
#include <game.h>

class Model : public GameObservable
{

private:
    Game* activeGame;
    bool running;

public:
    static const std::string EXIT_EXP;
    static const std::string QUIT_GAME_EXP;
    static const std::string START_GAME_EXP;

    Model();
    ~Model();
    Game* getCurrentGame();
    void quitGame();
    void startNewGame();
    bool isProgramRunning();
    void terminateProgram();

};

#endif // MODEL_H
