#include "game.h"

Game::Game()
{
    this->curQuestion = Question::pullNewQuestion();
    this->roundCounter = MIN_COUNT;
    this->curReward = rewards[MIN_COUNT];
    this->finished = false;
}

Game::~Game()
{
    delete curQuestion;
}

bool Game::isFinished()
{
    return finished;
}

int Game::getCurReward()
{
    return curReward;
}

int Game::getRoundCount()
{
    return roundCounter;
}

Question* Game::getCurQuestion()
{
    return curQuestion;
}

void Game::evaluateAnswer(std::string answer)
{
    if(finished == false && curQuestion->evaluateAnswer(answer))
    {
        roundCounter++;
        curReward = rewards[roundCounter];
        if(roundCounter >= MAX_COUNT)
        {
            finished = true;
        }
        else
        {
            delete curQuestion;
            curQuestion = Question::pullNewQuestion();
        }
    }
    else
    {
        finished = true;
        if(roundCounter >= SECOND_SECURITY_LEVEL_COUNT)
        {
            curReward = rewards[SECOND_SECURITY_LEVEL_COUNT];
        }
        else if(roundCounter >= FIRST_SECURITY_LEVEL_COUNT)
        {
            curReward = rewards[FIRST_SECURITY_LEVEL_COUNT];
        }
        else
        {
            curReward = rewards[MIN_COUNT];
        }
    }
}

Game* Game::startNewGame()
{
    return new Game();
}
