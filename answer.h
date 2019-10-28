#ifndef ANSWER_H
#define ANSWER_H

#include <string>

/**
 * @brief The Answer class is part of a question.
 * @author Mark Broderius
 */
class Answer
{

private:

    /**
     * @brief answer the answer string
     */
    std::string answer;

public:

    /**
     * @brief Answer constructs a new answer with a answer string.
     * @param string the answer string
     */
    Answer(std::string string);

    ~Answer();

    /**
     * @brief getAnswer returns the answer string of this answer
     * @return the answer string
     */
    std::string getAnswer();

};

#endif // ANSWER_H
