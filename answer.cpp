#include "answer.h"

Answer::Answer(std::string* answer)
{
    this->answer = *answer;
}

Answer::~Answer()
{

}

std::string* Answer::getAnswer()
{
    return &answer;
}
