#ifndef ANSWER_H
#define ANSWER_H

#pragma once

#include <string>

class Answer
{

private:
    std::string answer;

public:
    Answer(std::string string);
    ~Answer();
    std::string getAnswer();

};

#endif // ANSWER_H
