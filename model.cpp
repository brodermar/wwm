#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

Question Model::get_question()
{
    Question myQuestion("Frage", "A", "B", "C", "D", "B");
    return myQuestion;
}
