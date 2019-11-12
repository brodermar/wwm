#ifndef MODEL_H
#define MODEL_H

#include <thread>
#include <mutex>

#include <gameobservable.h>
#include <game.h>

/**
 * @brief The Model class represents the data of the complete program.
 */
class Model : public GameObservable
{

private:

    /**
     * @brief activeGame the current active game, can be nullptr
     */
    Game* activeGame;

    /**
     * @brief running true, if the program is running, false else
     */
    bool running;

    /**
     * @brief mutex a std::mutex object
     */
    std::mutex mutex;

public:

    /**
     * @brief EXIT_EXP a control statement which can be send to the controller
     * to exit the program
     */
    static const std::string EXIT_EXP;

    /**
     * @brief QUIT_GAME_EXP a control statement which can be send to the controller
     * to quit the current running game
     */
    static const std::string QUIT_GAME_EXP;

    /**
     * @brief START_GAME_EXP a control statement whicht can be send to the controller
     * to start a new game, possibly an already running game will be terminated
     */
    static const std::string START_GAME_EXP;

    /**
     * @brief Model constructs a new model
     */
    Model();

    ~Model();

    /**
     * @brief getCurrentGame return the current active game, can be nullptr
     * @return the current active game or nullptr
     */
    Game* getCurrentGame();

    /**
     * @brief quitGame terminated the current game
     */
    void quitGame();

    /**
     * @brief startNewGame starts a new game
     */
    void startNewGame();

    /**
     * @brief isProgramRunning checks if the program is still running
     * @return true, if the program is running, false else
     */
    bool isProgramRunning();

    /**
     * @brief terminateProgram terminates the program
     */
    void terminateProgram();

};

#endif // MODEL_H
