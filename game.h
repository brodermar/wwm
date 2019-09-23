#ifndef GAME_H
#define GAME_H

#include <question.h>
#include <string>

class Game
{

private:
    static constexpr int rewards[] = {0, 50, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 500000, 1000000};
    static const int MAX_COUNT = 15;
    static const int MIN_COUNT = 0;
    static const int FIRST_SECURITY_LEVEL_COUNT = 5;
    static const int SECOND_SECURITY_LEVEL_COUNT = 10;
    Question* curQuestion;
    int curReward;
    int roundCounter;
    bool finished;

public:
    Game();
    ~Game();
    bool isFinished();
    int getCurReward();
    int getRoundCount();
    Question* getCurQuestion();
    void evaluateAnswer(std::string answer);
    static Game* startNewGame();

};

#endif // GAME_H
