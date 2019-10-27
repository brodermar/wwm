#ifndef ANSWER_H
#define ANSWER_H

#include <string>

/**
 * @brief The Answer class
 */
class Answer
{

private:

    /**
     * @brief answer
     */
    std::string answer;

public:

    /**
     * @brief Answer
     * @param string
     */
    Answer(std::string string);

    /**
     *
     */
    ~Answer();

    /**
     * @brief getAnswer
     * @return
     */
    std::string getAnswer();

};

#endif // ANSWER_H
