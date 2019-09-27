#include "game.h"

const int Game::rewards[] = {0, 50, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 500000, 1000000};
const int Game::MAX_COUNT = 15;
const int Game::MIN_COUNT = 0;
const int Game::FIRST_SECURITY_LEVEL_COUNT = 5;
const int Game::SECOND_SECURITY_LEVEL_COUNT = 10;

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
        curReward = Game::rewards[roundCounter];
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
