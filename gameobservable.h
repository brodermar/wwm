#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>
#include <set>
#include <iterator>

class GameObservable
{

private:
    std::set<GameObserver*>* observers;

public:
    GameObservable();
    ~GameObservable();
    void add(GameObserver* observer);
    void remove(GameObserver* observer);
    void notify();

};

#endif // GAMEOBSERVABLE_H
