#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <stdexcept>

#include <answer.h>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The Question class represents a question of a game.
 */
class Question
{

private:

    /**
     * @brief question the questions string
     */
    std::string question;

    /**
     * @brief answerA the first answer
     */
    Answer* answerA;

    /**
     * @brief answerB the seconde answer
     */
    Answer* answerB;

    /**
     * @brief answerC the third answer
     */
    Answer* answerC;

    /**
     * @brief answerD the fourth answer
     */
    Answer* answerD;

    /**
     * @brief rightAnswer a pointer to the right answer
     */
    Answer* rightAnswer;

public:

    /**
     * @brief Question constructs a new question
     * @param question the question string
     * @param answerA the first answer
     * @param answerB the second answer
     * @param answerC the third answer
     * @param answerD the fourth answer
     * @param rightAnwser a pointer to the right answer
     */
    Question(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, char rightAnwser);

    ~Question();

    /**
     * @brief getQuestion returns the questions
     * @return the question string
     */
    std::string getQuestion();

    /**
     * @brief getAnswerA returns the first answer
     * @return the first answer
     */
    Answer* getAnswerA();

    /**
     * @brief getAnswerB returns the second answer
     * @return the second answer
     */
    Answer* getAnswerB();

    /**
     * @brief getAnswerC returns the third answer
     * @return the thrid answer
     */
    Answer* getAnswerC();

    /**
     * @brief getAnswerD returns the fourth answer
     * @return the fourth answer
     */
    Answer* getAnswerD();

    /**
     * @brief getRightAnswer return a pointer to the right answer
     * @return a pointer to the right answer
     */
    Answer* getRightAnswer();

    /**
     * @brief evaluateAnswer evaluates a given answer string to the question
     * @param answer a answer string
     * @return true, if answer matches the right answer, false else
     */
    bool evaluateAnswer(std::string answer);

    /**
     * @brief pullNewQuestion created and returns a new question
     * @return a new question
     */
    static Question* pullNewQuestion();

};

#endif // QUESTION_H
