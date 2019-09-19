#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <question.h>
class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    Question get_question();
signals:

public slots:
};

#endif // MODEL_H
