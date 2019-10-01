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
    qDebug() << "added observer" << endl;
}

void ViewObservable::removeObserver(ViewObserver* observer)
{
    observers->erase(observer);
    qDebug() << "erased observer" << endl;
}

void ViewObservable::notifyObservers(std::string message)
{
    qDebug() << "notify called with message: " << QString::fromStdString(message);
    std::set<ViewObserver*>::iterator iterator;
    for(iterator = observers->begin(); iterator != observers->end(); ++iterator)
    {
        (*iterator)->update(message);
    }
}
