#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>
#include <vector>

class GameObservable
{

private:
    std::vector<GameObserver>* observers;

public:
    virtual GameObservable();
    virtual ~GameObservable();
    add(GameObserver* observer);
    remove(GameObserver* observer);
    notify();

};

#endif // GAMEOBSERVABLE_H
