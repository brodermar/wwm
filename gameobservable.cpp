#include "gameobservable.h"

GameObservable::GameObservable()
{
    observers = std::set<GameObserver*>();
    qDebug() << "initialized new GameObserver" << endl;
}

GameObservable::~GameObservable()
{
    qDebug() << "~GameObservable() called" << endl;
}

GameObservable::GameObservable(const GameObservable& gameObservable)
{
    observers = gameObservable.observers;
}

void GameObservable::addObserver(GameObserver* observer)
{
    mutex.lock();
    observers.insert(observer);
    mutex.unlock();
    qDebug() << "added observer";
}

void GameObservable::removeObserver(GameObserver* observer)
{
    mutex.lock();
    observers.erase(observer);
    mutex.unlock();
    qDebug() << "erased observer";
}

void GameObservable::notifyObservers()
{
    qDebug() << "notify called";
    mutex.lock();
    for(std::set<GameObserver*>::iterator it = observers.begin(); it != observers.end(); ++it)
    {
        (*it)->update();
    }
    mutex.unlock();
}
