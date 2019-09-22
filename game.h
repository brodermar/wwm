#ifndef GAME_H
#define GAME_H

#include <question.h>
#include <string>

class Game
{

private:
    static constexpr int rewards[] = {0, 50, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 500000, 1000000};
    Question* curQuestion;
    int* curReward;
    int roundCounter;
    bool finished;

public:
    Game(Question* startQuestion);
    ~Game();
    bool isFinished();
    void finish();
    int* getCurReward();
    void setCurReward(int* reward);
    int getRoundCount();
    int setRoundCount(int roundCount);
    Question* getCurQuestion();
    void setCurQuestion(Question* question);

};

#endif // GAME_H
