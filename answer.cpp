#include "answer.h"

Answer::Answer(std::string answer)
{
    this->answer = answer;
}

Answer::~Answer()
{

}

std::string getAnswer()
{
    return this->answer;
}
