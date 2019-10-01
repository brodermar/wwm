#include "gameobservable.h"

GameObservable::GameObservable()
{
    this->observers = new std::set<GameObserver*>();
}

GameObservable::~GameObservable()
{
    delete this->observers;
}

void GameObservable::addObserver(GameObserver* observer)
{
    observers->insert(observer);
    qDebug() << "added observer";
}

void GameObservable::removeObserver(GameObserver* observer)
{
    observers->erase(observer);
    qDebug() << "erased observer";
}

void GameObservable::notifyObservers()
{
    qDebug() << "notify called";
    std::set<GameObserver*>::iterator iterator;
    for(iterator = observers->begin(); iterator != observers->end(); ++iterator)
    {
        (*iterator)->update();
    }
}
