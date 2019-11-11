#ifndef GAME_H
#define GAME_H

#include <question.h>

#include <string>
#include <mutex>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The Game class is part of the model and presesents one game.
 *
 * A game encapsulates its behaviour the it's status can be manipulated only
 * over a couple of functions.
 *
 * @author Mark Broderius
 */
class Game
{

private:

    /**
     * @brief rewards the rewards in their order allocated to the individual rounds
     */
    static const int rewards[];

    /**
     * @brief MAX_COUNT the maximum round count
     */
    static const int MAX_COUNT;

    /**
     * @brief MIN_COUNT the minimum round count
     */
    static const int MIN_COUNT;

    /**
     * @brief FIRST_SECURITY_LEVEL_COUNT the round count of 
     * the first security level
     */
    static const int FIRST_SECURITY_LEVEL_COUNT;

    /**
     * @brief SECOND_SECURITY_LEVEL_COUNT the round count of 
     * the second security level
     */
    static const int SECOND_SECURITY_LEVEL_COUNT;

    /**
     * @brief curQuestion the current question of the current 
     * round
     */
    Question* curQuestion;

    /**
     * @brief curReward the current reward of the current round
     * or the final reward, if the the game is finished
     */
    int curReward;

    /**
     * @brief roundCounter the count of the current round
     */
    int roundCounter;

    /**
     * @brief finished true, if the game is finished, false else
     */
    bool finished;

    /**
     * @brief mutex to lock and unlock data of the object
     */
    std::mutex mutex;

public:

    /**
     * @brief Game Constructs a new game
     */
    Game();

    ~Game();



    /**
     * @brief isFinished returns wether the game is finished or not
     * @return true, if the game is finished, false else
     */
    bool isFinished();

    /**
     * @brief getCurReward returns the current reward
     * @return the current reward
     */
    int getCurReward();

    /**
     * @brief getRoundCount returns the current round count
     * @return the current round count
     */
    int getRoundCount();

    /**
     * @brief getCurQuestion returns the current question
     * @return the current question
     */
    Question* getCurQuestion();

    /**
     * @brief evaluateAnswer evaluates an answer with the current
     * question, the status of the game will be changed
     * @param answer an answer string
     */
    void evaluateAnswer(std::string answer);

    /**
     * @brief startNewGame creates and returns a new game
     * @return a new game
     */
    static Game* startNewGame();

};

#endif // GAME_H
