#include "question.h"
#include <string>

Question::Question(QObject *parent) : QObject(parent)
{

}

Question::Question(const char q, const char a, const char b, const char c, const char d, const char correct)
{
    question = q;
    answer_a = a;
    answer_b = b;
    answer_c = c;
    answer_d = d;
    correct_answer = correct;
}

const char question;
const char answer_a;
const char answer_b;
const char answer_c;
const char answer_d;
const char correct_answer;
