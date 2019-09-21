#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>
#include <vector>

class GameObservable
{

private:
    std::vector<GameObserver>* observers;

public:
    GameObservable();
    virtual ~GameObservable();
    void add(GameObserver* observer);
    void remove(GameObserver* observer);
    void notify();

};

#endif // GAMEOBSERVABLE_H
