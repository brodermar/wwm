#include "viewobservable.h"

ViewObservable::ViewObservable()
{
    this->observers = new std::set<ViewObserver*>();
}

ViewObservable::~ViewObservable()
{
    delete this->observers;
}

void ViewObservable::add(ViewObserver* observer)
{
    observers->insert(observer);
}

void ViewObservable::remove(ViewObserver* observer)
{
    observers->erase(observer);
}

void ViewObservable::notify(Answer* answer)
{
    std::set<ViewObserver*>::iterator iterator;
    for(iterator = observers->begin(); iterator != observers->end(); ++iterator)
    {
        (*iterator)->update(answer);
    }
}
