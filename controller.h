#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
private:
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void start_game();

signals:

public slots:
};

#endif // CONTROLLER_H
