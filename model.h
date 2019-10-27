#ifndef MODEL_H
#define MODEL_H

#include <thread>
#include <mutex>

#include <gameobservable.h>
#include <game.h>

/**
 * @brief The Model class
 */
class Model : public GameObservable
{

private:

    /**
     * @brief activeGame
     */
    Game* activeGame;

    /**
     * @brief running
     */
    bool running;

    /**
     * @brief mutex
     */
    std::mutex mutex;

public:

    /**
     * @brief EXIT_EXP
     */
    static const std::string EXIT_EXP;

    /**
     * @brief QUIT_GAME_EXP
     */
    static const std::string QUIT_GAME_EXP;

    /**
     * @brief START_GAME_EXP
     */
    static const std::string START_GAME_EXP;

    /**
     * @brief Model
     */
    Model();

    ~Model();

    /**
     * @brief getCurrentGame
     * @return
     */
    Game* getCurrentGame();

    /**
     * @brief quitGame
     */
    void quitGame();

    /**
     * @brief startNewGame
     */
    void startNewGame();

    /**
     * @brief isProgramRunning
     * @return
     */
    bool isProgramRunning();

    /**
     * @brief terminateProgram
     */
    void terminateProgram();

};

#endif // MODEL_H
