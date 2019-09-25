#include "viewobservable.h"

ViewObservable::ViewObservable()
{
    this->observers = new std::set<ViewObserver*>();
}

ViewObservable::~ViewObservable()
{
    delete this->observers;
}

void ViewObservable::addObserver(ViewObserver* observer)
{
    observers->insert(observer);
}

void ViewObservable::removeObserver(ViewObserver* observer)
{
    observers->erase(observer);
}

void ViewObservable::notifyObservers(std::string message)
{
    std::set<ViewObserver*>::iterator iterator;
    for(iterator = observers->begin(); iterator != observers->end(); ++iterator)
    {
        (*iterator)->update(message);
    }
}
