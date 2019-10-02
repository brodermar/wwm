#ifndef GAME_H
#define GAME_H

#pragma once

#include <question.h>
#include <string>

class Game
{

private:
    static const int rewards[];
    static const int MAX_COUNT;
    static const int MIN_COUNT;
    static const int FIRST_SECURITY_LEVEL_COUNT;
    static const int SECOND_SECURITY_LEVEL_COUNT;
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
