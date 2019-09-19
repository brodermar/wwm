#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <QObject>

class Question : public QObject
{
private:

    Q_OBJECT
public:
    const char question;
    const char answer_a;
    const char answer_b;
    const char answer_c;
    const char answer_d;
    const char correct_answer;
    Question(const char question, const char answer_a, const char answer_b, const char answer_c, const char answer_d, const char correct_answer);
    explicit Question(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QUESTION_H
