#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>
#include <set>
#include <iterator>

#include <QDebug>
#include <QString>

class GameObservable
{

private:
    std::set<GameObserver*>* observers;

public:
    GameObservable();
    ~GameObservable();
    void addObserver(GameObserver* observer);
    void removeObserver(GameObserver* observer);
    void notifyObservers();

};

#endif // GAMEOBSERVABLE_H
