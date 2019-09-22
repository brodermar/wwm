#include "question.h"

Question::Question(std::string* question, std::string* answerA, std::string* answerB, std::string* answerC, std::string* answerD, char rightAnswer)
{
    this->question = *question;

    this->answerA = new Answer(answerA);
    this->answerB = new Answer(answerB);
    this->answerC = new Answer(answerC);
    this->answerD = new Answer(answerD);

    if(rightAnswer == 'a' || rightAnswer == 'A')
    {
        this->rightAnswer = this->answerA;
    }
    else if(rightAnswer == 'b' || rightAnswer == 'B')
    {
        this->rightAnswer = this->answerB;
    }
    else if(rightAnswer == 'c' || rightAnswer == 'C')
    {
        this->rightAnswer = this->answerC;
    }
    else if(rightAnswer == 'd' || rightAnswer == 'D')
    {
        this->rightAnswer = this->answerD;
    }
    else {
        throw std::invalid_argument("the value \"righAnswer\" hasn't a correct value");
    }
}

Question::~Question()
{
    delete answerA;
    delete answerB;
    delete answerC;
    delete answerD;
}

Answer* Question::getAnswerA()
{
    return answerA;
}

Answer* Question::getAnswerB()
{
    return answerB;
}

Answer* Question::getAnswerC()
{
    return answerC;
}

Answer* Question::getAnswerD()
{
    return answerD;
}

Answer* Question::getRightAnswer()
{
    return rightAnswer;
}
