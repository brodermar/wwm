#include "gameobservable.h"

GameObservable::GameObservable()
{
    this->observers = new std::vector(0);
}

GameObservable::~GameObservable()
{
    delete this->observers;
}

GameObservable::add(GameObserver* observer)
{

}

GameObservable::remove(GameObserver* observer)
{

}

GameObservable::notify()
{
    for()
}
