#ifndef GAME_H
#define GAME_H

#include <question.h>
#include <string>

/**
 * @brief The Game class
 */
class Game
{

private:

    /**
     * @brief rewards
     */
    static const int rewards[];

    /**
     * @brief MAX_COUNT
     */
    static const int MAX_COUNT;

    /**
     * @brief MIN_COUNT
     */
    static const int MIN_COUNT;

    /**
     * @brief FIRST_SECURITY_LEVEL_COUNT
     */
    static const int FIRST_SECURITY_LEVEL_COUNT;

    /**
     * @brief SECOND_SECURITY_LEVEL_COUNT
     */
    static const int SECOND_SECURITY_LEVEL_COUNT;

    /**
     * @brief curQuestion
     */
    Question* curQuestion;

    /**
     * @brief curReward
     */
    int curReward;

    /**
     * @brief roundCounter
     */
    int roundCounter;

    /**
     * @brief finished
     */
    bool finished;

public:

    /**
     * @brief Game
     */
    Game();

    ~Game();

    /**
     * @brief isFinished
     * @return
     */
    bool isFinished();

    /**
     * @brief getCurReward
     * @return
     */
    int getCurReward();

    /**
     * @brief getRoundCount
     * @return
     */
    int getRoundCount();

    /**
     * @brief getCurQuestion
     * @return
     */
    Question* getCurQuestion();

    /**
     * @brief evaluateAnswer
     * @param answer
     */
    void evaluateAnswer(std::string answer);

    /**
     * @brief startNewGame
     * @return
     */
    static Game* startNewGame();

};

#endif // GAME_H
