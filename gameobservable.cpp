#include "gameobservable.h"

GameObservable::GameObservable()
{
    this->observers = new std::set<GameObserver*>();
}

GameObservable::~GameObservable()
{
    delete this->observers;
}

void GameObservable::add(GameObserver* observer)
{
    observers->insert(observer);
}

void GameObservable::remove(GameObserver* observer)
{
    observers->erase(observer);
}

void GameObservable::notify()
{
   std::set<GameObserver*>::iterator iterator;
   for(iterator = observers->begin(); iterator != observers->end(); ++iterator)
   {
        (*iterator)->update();
   }
}
