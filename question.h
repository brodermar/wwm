#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <stdexcept>

#include <answer.h>

class Question
{

private:
    std::string question;

    Answer* answerA;
    Answer* answerB;
    Answer* answerC;
    Answer* answerD;

    Answer* rightAnswer;

public:
    Question(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, char rightAnwser);
    ~Question();

    std::string getQuestion();

    Answer* getAnswerA();
    Answer* getAnswerB();
    Answer* getAnswerC();
    Answer* getAnswerD();

    Answer* getRightAnswer();
    bool evaluateAnswer(std::string answer);

    static Question* pullNewQuestion();

};

#endif // QUESTION_H
