#ifndef MODEL_H
#define MODEL_H

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
    Game* getActiveGame();
    void quitGame();
    void setActiveGame(Game* game);
    bool isRunning();
    void exit();

};

#endif // MODEL_H
