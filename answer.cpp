#include "answer.h"

Answer::Answer(std::string answer)
{
    this->answer = answer;
    qDebug() << "initialized new Answer" << endl;
}

Answer::~Answer()
{
    qDebug() << "~Answer() called" << endl;
}

std::string Answer::getAnswer()
{
    return answer;
}
