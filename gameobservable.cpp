#include "gameobservable.h"

GameObservable::GameObservable()
{
    this->observers = new std::vector<GameObserver>(0);
}

GameObservable::~GameObservable()
{
    delete this->observers;
}

void GameObservable::add(GameObserver* observer)
{

}

void GameObservable::remove(GameObserver* observer)
{

}

void GameObservable::notify()
{

}
