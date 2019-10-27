#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <stdexcept>

#include <answer.h>

/**
 * @brief The Question class
 */
class Question
{

private:

    /**
     * @brief question
     */
    std::string question;

    /**
     * @brief answerA
     */
    Answer* answerA;

    /**
     * @brief answerB
     */
    Answer* answerB;

    /**
     * @brief answerC
     */
    Answer* answerC;

    /**
     * @brief answerD
     */
    Answer* answerD;

    /**
     * @brief rightAnswer
     */
    Answer* rightAnswer;

public:

    /**
     * @brief Question
     * @param question
     * @param answerA
     * @param answerB
     * @param answerC
     * @param answerD
     * @param rightAnwser
     */
    Question(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, char rightAnwser);

    ~Question();

    /**
     * @brief getQuestion
     * @return
     */
    std::string getQuestion();

    /**
     * @brief getAnswerA
     * @return
     */
    Answer* getAnswerA();

    /**
     * @brief getAnswerB
     * @return
     */
    Answer* getAnswerB();

    /**
     * @brief getAnswerC
     * @return
     */
    Answer* getAnswerC();

    /**
     * @brief getAnswerD
     * @return
     */
    Answer* getAnswerD();

    /**
     * @brief getRightAnswer
     * @return
     */
    Answer* getRightAnswer();

    /**
     * @brief evaluateAnswer
     * @param answer
     * @return
     */
    bool evaluateAnswer(std::string answer);

    /**
     * @brief pullNewQuestion
     * @return
     */
    static Question* pullNewQuestion();

};

#endif // QUESTION_H
